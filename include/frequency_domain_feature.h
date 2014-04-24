/**
 *@file
 *@brief 频域特征
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
*	频域特征
*
*/

//快速傅里叶变换
fm_vec fft(const vec& signal,const int fs);
	
//峰值点频率
value_t peak_frequency(const fm_vec& fft_signal);
value_t peak_frequency(const vec& signal,const int fs);

//功率谱平均频率
value_t mean_frequency(const fm_vec& fft_signal);
value_t mean_frequency(const vec& signal,const int fs);

//高低频幅值比
value_t frequency_ratio(const fm_vec& fft_signal,value_t low,value_t high);
value_t frequency_ratio(const vec& signal,const int fs,value_t low,value_t high);





}










#endif // !frequency_domain_feature_h









