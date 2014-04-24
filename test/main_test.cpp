/*
*  Normal Feature Extraction 
*             by Syndrome(Issac)
*			  (issac.sacrifice@gmail.com)
*             From Zhejiang Uinversity
*			  
*
*/

#include"global.h"
#include"time_domain_feature.h"
#include"frequency_domain_feature.h"

using namespace NorFE;

int test_time_domain_feature(const vec& signal);

int test_frequency_domain_feature(const vec& signal);

int main()
{
	vec signal;
	value_t sig[]={1, -3, 3, 7, 5, 6, 11, 4, 9, 3, 1, -1};
	for(int i=0;i<12;i++)
		signal.push_back(sig[i]);

	//Ê±ÓòÌØÕ÷²âÊÔ
	//test_time_domain_feature(signal);

	//ÆµÓòÌØÕ÷²âÊÔ
	test_frequency_domain_feature(signal);

	return 0;
}


int test_time_domain_feature(const vec& signal)
{
	std::cout<<"mean_absolute:"<<mean_absolute(signal)<<std::endl;
	std::cout<<"integration_absolute:"<<integration_absolute(signal)<<std::endl;
	std::cout<<"variance:"<<variance(signal)<<std::endl;
	std::cout<<"root_mean_square:"<<root_mean_square(signal)<<std::endl;
	std::cout<<"energy:"<<energy(signal)<<std::endl;
	std::cout<<"Histogram:";
	vec hist=histogram(signal,5);
	for(int i=0;i<hist.size();i++)
		std::cout<<hist[i]<<' ';
	std::cout<<std::endl;
	std::cout<<"Wave_ength"<<wave_length(signal)<<std::endl;

	getchar();
	return 1;
}


int test_frequency_domain_feature(const vec& signal)
{
	/*
	value_t sig[]={1, -3, 3, 7, 5, 6, 11, 4, 9, 3, 1, -1};
	value_t sig[]={1, -3, 3, 7, 5, 6, 11, 4, 9, 3, 1, -1, 0, 0, 0, 0};
	fftw_plan p;
	fftw_complex *out;
	int N=16;
	out=(fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);

	p=fftw_plan_dft_r2c_1d(N,sig,out,FFTW_ESTIMATE);

	fftw_execute(p); 

	for(int i=0;i<N;i++)
		std::cout<<out[i][0]<<' '<<out[i][1]<<std::endl;
	fftw_destroy_plan(p);
	fftw_free(out);
	*/

	std::cout<<"the Spectrum of the signal:"<<std::endl<<"frequency"<<" "<<"magnitude"<<std::endl;
	fm_vec fft_s=fft(signal,100);
	for(int i=0;i<fft_s.size();i++)
		std::cout<<fft_s[i].f<<' '<<fft_s[i].m<<std::endl;

	return 1;
}




