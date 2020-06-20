/*
*	waveform.c
* gentone - Fernando Garcia de la Cruz
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
double *waveform(double frequency, double samples, double Fs, char *wave, double amp){
	int i;
	double	pi=3.141592653;
	double	x=0.0;
	double *y;
	if (strcmp(wave,"sine") == 0){
		y=(double *)malloc((int)samples*sizeof(double));
		for (i=0; i<samples; i++){ //Getting samples
			x=2*pi*(frequency/Fs)*(double)i;
			y[i] = amp*sin(x);
		}
		return(y);
	}
	
	if (strcmp(wave,"square") == 0){
		y=(double *)malloc((int)samples*sizeof(double));
		for (i=0; i<samples; i++){ //Getting samples
			x=2*pi*(frequency/Fs)*(double)i;
			y[i] = sin(x);
			if (y[i] > 0) y[i] = amp;
			if (y[i] == 0) y[i] = 0;
			if (y[i] < 0) y[i] = -amp;
		}
		return(y);
	}

	if (strcmp(wave,"sawtooth") == 0){ //https://en.wikipedia.org/wiki/Sawtooth_wave
		y=(double *)malloc((int)samples*sizeof(double));
		for (i=0; i<samples; i++){ //Getting samples
			x=2*pi*(frequency/Fs)*(double)i-pi;
			y[i] = -(2*amp/pi)*atan(cos(x/2)/sin(x/2));
		}
		return(y);
	}

	if (strcmp(wave,"triangle") == 0){ //https://en.wikipedia.org/wiki/Triangle_wave (absolute of sawtooth)
		y=(double *)malloc((int)samples*sizeof(double));
		for (i=0; i<samples; i++){ //Getting samples
			x=2*pi*(frequency/Fs)*(double)i-(pi/2);
			y[i] = 2*fabs(-(2*amp/pi)*atan(cos(x/2)/sin(x/2)))-amp;
		}
		return(y);
	}
	return(0);
}
