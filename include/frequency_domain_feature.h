/**
 *@file
 *@brief Ƶ������
 *@author HLF(issac.sacrifice@gmail.com,from Zhejiang University)
 *
 */

#ifdef _MSC_VER>1200
#pragma once
#endif

#ifndef _NorFE_frequency_domain_feature_h
#define _NorFE_frequency_domain_feature_h

#include"global.h"


namespace NorFE{

/*
*	@defgroup frequency_domain_feature
*	Ƶ������
*
*/

//���ٸ���Ҷ�任
fm_vec fft(const vec& signal,const int fs);
	
//��ֵ��Ƶ��
value_t peak_frequency(const fm_vec& fft_signal);
value_t peak_frequency(const vec& signal,const int fs);

//������ƽ��Ƶ��
value_t mean_frequency(const fm_vec& fft_signal);
value_t mean_frequency(const vec& signal,const int fs);

//�ߵ�Ƶ��ֵ��
value_t frequency_ratio(const fm_vec& fft_signal,value_t low,value_t high);
value_t frequency_ratio(const vec& signal,const int fs,value_t low,value_t high);





}










#endif // !frequency_domain_feature_h









