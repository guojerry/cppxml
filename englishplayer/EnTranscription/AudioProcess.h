#pragma once

#include "AudioDoc.h"
#include "Mfcc.h"

class CAudioProcess
{
public:
	CAudioProcess(CAudioDoc* pParent);
	virtual ~CAudioProcess(void);

public:
	void Init(int nChannels);
	void ProcessSample(char* pDataIn, DWORD dwSampleCounts);
	void GetDrawData(int eType, float* pData, int& nLen);

private:
//	CMfcc m_mfcc;
	short m_buffer[2][FFT_LEN];
	float m_waveform[4][FFT_LEN];		//Get to draw waveform, time domain
	float m_cep[4][MFCCVECTOR];			//Get to draw cepstrum, qerfuency domain
	float m_frequency[4][FREQBAND];		//Get to draw spectrum, frequency domain 
	double m_eTotalEnergy;
	long m_nTotalWindow;
	CAudioDoc* m_pParent;
	int m_nCurrentIndex;
	int m_nChannels;
	float64 m_eMeans[2];		//Max 2 channels
};
