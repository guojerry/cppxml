#include "StdAfx.h"
#include "AudioDoc.h"
#include "Mfcc.h"
#include "fe_warp.h"

int32 fe_start_utt(fe_t * fe)
{
	fe->num_overflow_samps = 0;
	memset(fe->overflow_samps, 0, fe->frame_size * sizeof(int16));
	fe->start_flag = 1;
	fe->prior = 0;
	return 0;
}

CMfcc::CMfcc(void)
{
	m_fe = new fe_t;

	//Do parameters initialization
	m_fe->sampling_rate = SAMPLE_RATE;
	m_fe->frame_rate = 100;
	m_fe->dither = 1;		//Do dither
	m_fe->seed = -1;		//For dither random data seed, -1 using defaults: time()
	m_fe->swap = 0;			//WORDS_LITTLEENDIAN
	m_fe->window_length = float32(SAMPLE_INTERVAL*1.0 / 1000);
	m_fe->pre_emphasis_alpha = float32(0.97);	//Pre emphasis alpha
	m_fe->num_cepstra = MFCCVECTOR;	//13 spectra components
	m_fe->fft_size = 512;	//For 10ms samples, it will be 441, fft size must greater than it.

	/* Check FFT size, compute FFT order (log_2(n)) */
	int j = m_fe->fft_size;
	m_fe->fft_order = 0;
	for(; j > 1; j >>= 1, m_fe->fft_order++) 
	{
		if (((j % 2) != 0) || (m_fe->fft_size <= 0)) 
		{
			TRACE("fft: number of points must be a power of 2 (is %d)\n", m_fe->fft_size);
			goto error;
		}
	}

	/* Verify that FFT size is greater or equal to window length. */
	if(m_fe->fft_size < (int)(m_fe->window_length * m_fe->sampling_rate)) 
	{
		TRACE("FFT: Number of points must be greater or equal to frame size (%d samples)\n",
			(int)(m_fe->window_length * m_fe->sampling_rate));
		goto error;
	}

	m_fe->remove_dc = 1;
	m_fe->transform = LEGACY_DCT;
	m_fe->log_spec = 0;//SMOOTH_LOG_SPEC;
	//End parameter initialization

	/* compute remaining fe parameters */
	/* We add 0.5 so approximate the float with the closest
	* integer. E.g., 2.3 is truncate to 2, whereas 3.7 becomes 4
	*/
	m_fe->frame_shift = (int32) (m_fe->sampling_rate / m_fe->frame_rate + 0.5);
	m_fe->frame_size = (int32) (m_fe->window_length * m_fe->sampling_rate + 0.5);
	m_fe->prior = 0;
	m_fe->frame_counter = 0;

	if (m_fe->frame_size > (m_fe->fft_size)) 
	{
		TRACE("Number of FFT points has to be a power of 2 higher than %d\n", (m_fe->frame_size));
		goto error;
	}

	if(m_fe->dither)
		fe_init_dither(m_fe->seed);

	/* establish buffers for overflow samps and hamming window */
	m_fe->overflow_samps = new int16[m_fe->frame_size];
	m_fe->hamming_window = new window_t[m_fe->frame_size/2];

	/* create hamming window */
	fe_create_hamming(m_fe->hamming_window, m_fe->frame_size);

	/* init and fill appropriate filter structure */
	m_fe->mel_fb = new melfb_t;
	//Init mel fb
	m_fe->mel_fb->sampling_rate = m_fe->sampling_rate;
	m_fe->mel_fb->fft_size = m_fe->fft_size;
	m_fe->mel_fb->num_cepstra = m_fe->num_cepstra;
	m_fe->mel_fb->num_filters = 80;
	if(m_fe->log_spec == RAW_LOG_SPEC)
		m_fe->feature_dimension = m_fe->mel_fb->num_filters;
	else
		m_fe->feature_dimension = m_fe->num_cepstra;

	m_fe->mel_fb->upper_filt_freq = float32(6855.4976);
	m_fe->mel_fb->lower_filt_freq = float32(133.33334);
	m_fe->mel_fb->doublewide = 0;
	m_fe->mel_fb->warp_type = "inverse_linear";
	m_fe->mel_fb->warp_params = NULL;
	m_fe->mel_fb->lifter_val = 0;
	m_fe->mel_fb->unit_area = 1;
	m_fe->mel_fb->round_filters = 1;

	if (fe_warp_set(m_fe->mel_fb, m_fe->mel_fb->warp_type) != FE_SUCCESS) 
	{
		E_ERROR("Failed to initialize the warping function.\n");
		goto error;
	}
	fe_warp_set_parameters(m_fe->mel_fb, m_fe->mel_fb->warp_params, m_fe->mel_fb->sampling_rate);

	/* transfer params to mel fb */
	fe_build_melfilters(m_fe->mel_fb);
	fe_compute_melcosine(m_fe->mel_fb);

	/* Create temporary FFT, spectrum and mel-spectrum buffers. */
	/* FIXME: Gosh there are a lot of these. */
	m_fe->spch = new int16[m_fe->frame_size];
	m_fe->frame = new frame_t[m_fe->fft_size];
	m_fe->spec = new powspec_t[m_fe->fft_size];
	m_fe->mfspec = new powspec_t[m_fe->mel_fb->num_filters];

	/* create twiddle factors */
	m_fe->ccc = new frame_t[m_fe->fft_size / 4];
	m_fe->sss = new frame_t[m_fe->fft_size / 4];
	fe_create_twiddle(m_fe);

	/*** Z.A.B. ***/
	/*** Initialize the overflow buffers ***/
	fe_start_utt(m_fe);
	
	return;

error:
	fe_free(m_fe);
	m_fe = NULL;
}

CMfcc::~CMfcc(void)
{
	fe_free(m_fe);
	m_fe = NULL;
}

int CMfcc::fe_free(fe_t * fe)
{
	if (fe == NULL)
		return 0;

	/* kill FE instance - free everything... */
	if (fe->mel_fb) 
	{
		if (fe->mel_fb->mel_cosine)
			delete [] fe->mel_fb->mel_cosine;
		delete [] fe->mel_fb->lifter;
		delete [] fe->mel_fb->spec_start;
		delete [] fe->mel_fb->filt_start;
		delete [] fe->mel_fb->filt_width;
		delete [] fe->mel_fb->filt_coeffs;
		delete [] fe->mel_fb;
	}
	delete [] fe->spch;
	delete [] fe->frame;
	delete [] fe->ccc;
	delete [] fe->sss;
	delete [] fe->spec;
	delete [] fe->mfspec;
	delete [] fe->overflow_samps;
	delete [] fe->hamming_window;
	
	delete fe;

	return 0;
}

int32 CMfcc::fe_process_frame(int16 const *spch, int32 nsamps, mfcc_t* fr_cep)
{
	fe_read_frame(m_fe, spch, nsamps);
	return fe_write_frame(m_fe, fr_cep);
}
