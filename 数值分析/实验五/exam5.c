#include <stdio.h>
#include <Windows.h>

double chashang(int n,double X[],double Y[]) {
	double f = 0;
	double temp = 0;
	int i,j;
	for (i = 0; i <= n; i++) {
		temp = Y[i];
		for (j = 0; j <= n; j++) {
			if (i != j) temp /= (X[i] - X[j]);
		}
		f += temp;
	}
	return f;
}

double Newton(double x, double X[], double Y[]) {
	double result = 0; 
	double temp,f;
	int i,j;
	for (i = 0; i < 5; i++) {
		temp = 1;
		f = chashang(i,X,Y);
		for (j = 0; j < i; j++) {
			temp *= (x - X[j]);
		}
		result += f*temp;
	}
	return result;
}

int main() {
	double X[5] = {0.4,0.55,0.8,0.9,1};
	double Y[5] = { 0.41075,0.57815,0.88811,1.02652,1.17520 };
	double x1 = 0.5;
	double x2 = 0.7;
	double x3 = 0.85;
	printf("f(%f) = %f\n",x1, Newton(x1,X,Y));
	printf("f(%f) = %f\n",x2, Newton(x2, X, Y));
	printf("f(%f) = %f\n",x3, Newton(x3, X, Y));
	system("pause");
	return 0;
}