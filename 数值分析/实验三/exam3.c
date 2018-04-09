#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void zhuigan(double a[6],double b[6],double c[5],double f[6]) {
	double u[5],l[6],y[6],x[6];
	int i , n = 5;
	u[0] = 0;
	y[0] = 0;
	a[1] = 0;
	for (i = 1; i <= n; i++) {
		l[i] = b[i] - a[i] * u[i - 1];
		if (l[i] == 0) {
			printf("l[i] = 0 Í£Ö¹¼ÆËã");
			exit(1);
		}
		else {
			y[i] = (f[i] - a[i] * y[i - 1]) / l[i];
			if (i == n) {
			}
			else {
				u[i] = c[i] / l[i];
			}
		}
	}
	x[n] = y[n];
	for (i = n - 1; i > 0; i--) {
		x[i] = y[i] - u[i] * x[i + 1];
	}
	for (i = 1; i <= n;i++) {
		printf("x[%d] = %f\n",i,x[i]);
	}
	for (i = 1; i <= n; i++) {
		printf("y[%d] = %f\n",i,y[i]);
	}
}

int main() {
	double a[6] = { 0,0,-1,-1,-1,-1 };
	double b[6] = { 0,2,2,2,2,2 };
	double c[5] = { 0,-1,-1,-1,-1 };
	double f[6] = { 0,1,0,0,0,0 };
	zhuigan(a,b,c,f);
	system("pause");
	return 0;
}