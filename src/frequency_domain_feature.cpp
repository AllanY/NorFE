
#include"frequency_domain_feature.h"


namespace NorFE{


//快速傅里叶变换
fm_vec fft(const vec& signal,const int fs)
{
	fm_vec fft_sig;
	int N=0;
	int Ni=signal.size();//Ni为12，N为16；
	while(Ni){
		Ni=Ni/2;
		N++;
	}
	N=pow(2,N);
	Ni=signal.size();
	//std::cout<<N<<std::endl;;
	fftw_plan p;
	fftw_complex *out;
	value_t *sig;

	sig=new value_t[N];
	out=new fftw_complex[N];

	for(int i=0;i<Ni;i++)
		sig[i]=signal[i];
	for(int i=Ni;i<N;i++)
		sig[i]=0;
	
	out=(fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
	p=fftw_plan_dft_r2c_1d(N,sig,out,FFTW_ESTIMATE);

	fftw_execute(p);

	FrequencyMagnitude node;
	for(int i=0;i<N/2+1;i++){
		node.m=2*sqrt(out[i][0]*out[i][0]+out[i][1]*out[i][1])/Ni;
		node.f=1.0*fs/2*i/(N/2);
		fft_sig.push_back(node);
	}

	fftw_destroy_plan(p);
	fftw_free(out);
	if(sig)
		delete[] sig;

	return fft_sig;
}

//峰值点频率
value_t peak_frequency(const fm_vec& fft_signal)
{
	FrequencyMagnitude node=fft_signal[0];

	for(int i=1;i<fft_signal.size();i++)
		if(node.m<fft_signal[i].m)
			node=fft_signal[i];

	return node.f;
}

value_t peak_frequency(const vec& signal,const int fs)
{
	return peak_frequency(fft(signal,fs));
}


//功率谱平均频率
value_t mean_frequency(const fm_vec& fft_signal)
{
	value_t mean=0;
	value_t m_sum=0;

	for(int i=0;i<fft_signal.size();i++){
		mean=mean+fft_signal[i].f*fft_signal[i].m;
		m_sum=m_sum+fft_signal[i].m;
	}

	return mean/m_sum;
}

value_t mean_frequency(const vec& signal,const int fs)
{
	return mean_frequency(fft(signal,fs));
}


//高低频幅值比
value_t frequency_ratio(const fm_vec& fft_signal,value_t low,value_t high)
{
	value_t low_sum=0,high_sum=0;
	for(int i=0;i<fft_signal.size()*low;i++)
		low_sum+=fft_signal[i].m;
	for(int i=fft_signal.size()*low;i<fft_signal.size()*high;i++)
		high_sum+=fft_signal[i].m;
	
	if(high_sum==0)
		return -1;
	else
		return low_sum/high_sum;
}

value_t frequency_ratio(const vec& signal,const int fs,value_t low,value_t high)
{
	return frequency_ratio(fft(signal,fs),low,high);
}





}










