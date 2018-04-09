//#include <stdio.h>
//#include <Windows.h>
//#include <math.h>
//
//double f_1(double x);
//double f_2(double x);
//
//void xps(double a,double b,int n, double(*f)(double)) {
//	double h = (b - a) / n;
//	int i;
//	double s = f(a) - f(b);
//	double x;
//	x = a;
//	for (i = 1; i <= n; i++) {
//		x += h / 2;
//		s += 4 * f(x);
//		x += h / 2;
//		s += 2 * f(x);
//	}
//	s *= (h / 6);
//	printf("%f\n",s);
//}
//
//double f_1(double x) {
//	return x * exp(x);
//}
//double f_2(double x) {
//	return 4 / (1 + x*x);
//}
//int main() {
//	printf("e^2 = ");
//	xps(1, 2, 8, f_1);
//	printf("pai = ");
//	xps(0, 1, 8, f_2);
//	system("pause");
//	return 0;
//}