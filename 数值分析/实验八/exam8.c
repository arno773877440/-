#include <stdio.h>
#include <Windows.h>
#include <math.h>

double f(double x, double y) {
	return (2.0/3)*x*(1/(y*y));
}
double ff(double x){
	return pow(1+x*x,1.0/3);
}

void Euler(double a,double b,double h,double x0,double y0) {
	int i, n;
	double T1, T2,T3;
	n = (b-a)/h;
	for (i = 0; i <= n - 1; i++) {
		T1 = y0 + h * f(x0, y0);
		T3 = ff(x0);
		x0 += h;
		T2 = y0 + h * f(x0, T1);
		y0 = (T1 + T2) / 2;
		printf("x[%d] = %f, y[%d] = %f\ty[%f] = %f\n",i,x0,i,y0,x0,T3);
	}
}

int main() {
	double a,b,h,x0,y0;
	a = 0;
	b = 1;
	h = 0.1;
	x0 = 0;
	y0 = 1;
	Euler(a,b,h,x0,y0);
	system("pause");
	return 0;
}