/**
 *@file
 *@brief ʱ������
 *@author HLF(issac.sacrifice@gmail.com,from Zhejiang University)
 *
 */

#ifdef _MSC_VER>1200
#pragma once
#endif

#ifndef _NorFE_time_domain_feature_h
#define _NorFE_time_domain_feature_h

#include"global.h"


namespace NorFE
{

/*
*	@defgroup time_domain_feature
*	ʱ��������
*
*/

//����ֵ����
inline value_t integration_absolute(const vec& signal);

//����ֵƽ��ֵ
value_t mean_absolute(const vec& signal);

//����
value_t variance(const vec& signal);

//����
value_t energy(const vec& signal);

//������
value_t root_mean_square(const vec& signal);

//ֱ��ͼ
vec histogram(const vec& signal,const int nblock);

//���γ���
value_t wave_length(const vec& signal);

}




#endif



