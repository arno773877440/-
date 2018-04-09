//#include <stdio.h>
//#include <math.h>
//#include <windows.h>
//
//double fun(double x) {
//	return exp(x) + 10 * x - 2;
//}
//
//void erfen(double a, double b, double theta, int N) {
//	double y1, y2, x, y;
//	int k;
//	y1 = fun(a);
//	y2 = fun(b);
//	if (y1*y2 > 0) {
//		printf("error");
//	}
//	else {
//		for (k = 1; k <= N; k++) {
//			x = (a + b) / 2;
//			y = fun(x);
//			if (fabs(y) < theta) {
//				printf("k = %d\tx = %f\ty = %f\n", k, x, y);
//				return;
//			}
//			else if(y1*y < 0){
//				b = x;
//				y2 = fun(b);
//			}
//			else if(y2*y < 0){
//				a = x;
//				y1 = fun(a);
//			}
//		}
//	}
//}
//
//double gongshi(double x) {
//	return (2 - exp(x)) / 10;
//}
//void diedai(double x0,double theta,int N) {
//	int k;
//	double x1;
//	for(k = 1; k <= N;k++) {
//		x1 = gongshi(x0);
//		if (fabs(x0 - x1) < theta) {
//			printf("k = %d\tx = %f\n",k,x1);
//			return;
//		}
//		else {
//			x0 = x1;
//		}
//		
//	}
//	printf("error\n");
//	
//}
//
//int main() {
//	double theta = 0.5e-3;
//	printf("二分法： ");
//	erfen(0.0,1.0,theta,15);
//	printf("迭代法： ");
//	diedai(0.0,theta,100);
//	system("pause");
//	return 0;
//}
