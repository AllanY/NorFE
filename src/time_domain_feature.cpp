#include"time_domain_feature.h"



namespace NorFE
{


inline value_t integration_absolute(const vec& signal)
{
	value_t sum_abs=0;
	for(int i=0;i<signal.size();i++)
		sum_abs+=fabs(signal[i]);

	return sum_abs;
}


value_t mean_absolute(const vec& signal)
{
	return integration_absolute(signal)/signal.size();
}


value_t variance(const vec& signal)
{
	value_t sum_var=0;
	value_t d_mean=mean_absolute(signal);
	for(int i=0;i<signal.size();i++)
		sum_var+=pow((signal[i]-d_mean),2);

	return sum_var/(signal.size()-1);
}


value_t energy(const vec& signal)
{
	value_t sum_eng=0;
	for(int i=0;i<signal.size();i++)
		sum_eng+=pow(signal[i],2);

	return sum_eng;
}


value_t root_mean_square(const vec& signal)
{
	return sqrt(energy(signal)/signal.size());
}


vec histogram(const vec& signal,const int nblock)
{
	value_t s_min=1e10,s_max=-1e10,delta;
	vec hist(nblock);

	for(int i=0;i<signal.size();i++){
		if(signal[i]<s_min)
			s_min=signal[i];
		if(signal[i]>s_max)
			s_max=signal[i];
	}

	s_max+=1e-10;
	delta=(s_max-s_min)/nblock;
	for(int i=0;i<signal.size();i++)
		for(int j=0;j<nblock;j++)
			if(signal[i]>=s_min+j*delta&&signal[i]<s_min+(j+1)*delta)
				hist[j]++;

	return hist;
}

value_t wave_length(const vec& signal)
{
	value_t WL=0;
	for(int i=0;i<signal.size()-1;i++)
		WL+=fabs(signal[i]-signal[i+1]);
	return WL;
}

}











