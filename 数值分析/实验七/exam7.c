#include <stdio.h>
#include <windows.h>
#include <math.h>

double f(double h,int k) {
	h /= pow(2,k);
	return (exp(1+h)-exp(1-h))/(2*h);
}

int main() {
	double h;
	int i,n;
	h = 0.8;
	n = 10;
	for(i =0;i<=n;i++){
		printf("%f\n",f(h,i));
	}
	system("pause");
	return 0;
}