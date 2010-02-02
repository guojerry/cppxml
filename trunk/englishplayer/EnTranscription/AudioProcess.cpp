#include "StdAfx.h"
#include "AudioProcess.h"
#include <math.h>

CAudioProcess::CAudioProcess(CAudioDoc* pParent)
:m_pParent(pParent)
{
	Init(2);
}

CAudioProcess::~CAudioProcess(void)
{
}

void CAudioProcess::Init(int nChannels)
{
	m_nCurrentIndex = 0;
	m_eTotalEnergy = 0;
	m_nTotalWindow = 0;
	m_nChannels = nChannels;
}

void CAudioProcess::ProcessSample(char* pDataIn, DWORD dwSampleCounts)
{
	ASSERT(dwSampleCounts <= FFT_LEN);
	WORD* pBuffer = (WORD*)pDataIn;

	unsigned int i = 0;
	int j = 0;
	for(i = 0; i < dwSampleCounts; i++)
	{
		for(j = 0; j < m_nChannels; j++)
		{
			m_buffer[j][i] = short(*pBuffer);
			pBuffer++;
			m_eMeans[j] += m_buffer[j][i];
		}
	}
	for(j = 0; j < m_nChannels; j++)
		m_eMeans[j] = m_eMeans[j] / dwSampleCounts;

	//Remove DC and Calculate energy
	float64 lEnergy = 0;
	float64 ftmp = 0;
	int nBase = ((m_nCurrentIndex + 1) % 2) * 2;
	for(i = 0; i < dwSampleCounts; i++)
	{
		for(j = 0; j < 1/*m_nChannels*/; j++)
		{
			ftmp = m_buffer[j][i];// - m_eMeans[j];
			lEnergy += ftmp * ftmp;
			m_waveform[nBase + j][i] = float(ftmp);
		}
	}
	lEnergy /= dwSampleCounts;
	m_eTotalEnergy += lEnergy;
	m_nTotalWindow++;
	int nRelEnergy = int(lEnergy * m_nTotalWindow * 100 / m_eTotalEnergy);
	if(m_pParent)
		m_pParent->UpdateEnergy(nRelEnergy);

	m_nCurrentIndex = (m_nCurrentIndex + 1) % 2;
//	int16 nCep = m_mfcc->fe_process_frame((const int16*)m_leftbuffer, FFT_LEN, m_cep);
//	nCep = m_mfcc->fe_process_frame((const int16*)m_rightbuffer, FFT_LEN, m_cep);
}

void CAudioProcess::GetDrawData(int eType, float* pData, int& nLen)
{
	int nBase = m_nCurrentIndex * 2;
	switch(eType)
	{
	case CAudioDoc::eDrawWaveform:
		{
			if(pData != NULL)
			{
				memcpy_s(pData, nLen * sizeof(float), m_waveform[nBase], sizeof(float) * FFT_LEN);
				nLen = min(FFT_LEN, nLen);
			}
			else
				nLen = FFT_LEN;
			break;
		}
	case CAudioDoc::eDrawSpectrum:
		{
			if(pData != NULL)
			{
				memcpy_s(pData, nLen * sizeof(float), m_frequency[nBase], sizeof(float) * FREQBAND);
				nLen = min(FREQBAND, nLen);
			}
			else
				nLen = FREQBAND;
			break;
		}
	case CAudioDoc::eDrawCepstrum:
		{
			if(pData != NULL)
			{
				memcpy_s(pData, nLen * sizeof(float), m_cep[nBase], sizeof(float) * MFCCVECTOR);
				nLen = min(MFCCVECTOR, nLen);
			}
			else
				nLen = MFCCVECTOR;
			break;
		}
	default:
		break;
	}
}
