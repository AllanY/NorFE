/**
 *
 *  Normal Feature Extraction 
 *             by Syndrome(Issac) 
 *             From Zhejiang Uinversity
 *@file
 *@brief 时域特征
 *@author HLF(issac.sacrifice@gmail.com,from Zhejiang University)
 *
 */

#ifdef _MSC_VER>1200
#pragma once
#endif

#ifndef _NorFE_global_h
#define _NorFE_global_h

#ifdef _MSC_VER
#pragma warning(disable:4215 4018)
#endif

/*
#if defined (_WIN32) && defined(BUILD_SHARED_LIBS)
#  if defined(SMFE_BUILD)
#    define SMFE_EXPORT __declspec(dllexport)
#  else
#    define SMFE_EXPORT  __declspec(dllimport)
#  endif
#else
#    define SMFE_EXPORT
#endif

*/

#include<vector>
#include<stdio.h>
#include<math.h>
#include<iostream>
#include"fftw3.h"

#define pi 3.141592

namespace NorFE
{

/**
 *
 *@defgroup global global
 *定义数据结构
 *
 */

typedef double value_t;

typedef std::vector<double> vec;

struct FrequencyMagnitude{
	value_t f;
	value_t m;
};
typedef std::vector<FrequencyMagnitude> fm_vec;


}










#endif








