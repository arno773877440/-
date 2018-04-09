//#include <stdio.h>
//#include <windows.h>
//
//double f(double a) {
//	
//}
//
//void longbeige(double a,double b,double deta) {
//	double h = b - a;
//	double R1, R2, s,S,x,S2,S1;
//	double T1 = h * (f(a) + f(b)) / 2;
//	double T2;
//	double C1,C2;
//	int k = 1;
//	do {
//		S = 0; x = a + h / 2;
//		do {
//			S += f(x);
//			x += h;
//		} while (x < b);
//		T2 = T1 / 2 + (h / 2)*s;
//		S2 = T2 + (T2 - T1) / 3;
//		if (k == 1) {
//			k += 1;
//			h /= 2;
//			T1 = T2;
//			S1 = S2;
//		}
//		else {
//			C2 = S2 + (S2 - S1) / 15;
//			if (k == 2) {
//				C1 = C2;
//			}
//			else {
//				R2 = C2 + (C2 - C1) / 63;
//				if (k >= 3) {
//					R1 = R2;
//				}
//			}
//		}
//	} while (R2 - R1 >= deta);
//	printf("R2 = %f",R2);
//}
//
//int main() {
//
//	return 0;
//}