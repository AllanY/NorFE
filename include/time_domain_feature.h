/**
 *@file
 *@brief 时域特征
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
*	时间域特征
*
*/

//绝对值积分
inline value_t integration_absolute(const vec& signal);

//绝对值平均值
value_t mean_absolute(const vec& signal);

//方差
value_t variance(const vec& signal);

//能量
value_t energy(const vec& signal);

//均方根
value_t root_mean_square(const vec& signal);

//直方图
vec histogram(const vec& signal,const int nblock);

//波形长度
value_t wave_length(const vec& signal);

}




#endif



