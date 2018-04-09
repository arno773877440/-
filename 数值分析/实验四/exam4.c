#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include <stdlib.h>

int Jacobi(int n,double A[7][7],double b[7],double dert,int N,double x[7],double y[7]) {
	int i,j,k;
	double e;
	double a_sum;

	for (k = 1; k <= N; k++) {
		for (i = 1; i <= n; i++) {
			a_sum = 0;
			for (j = 1; j <= n; j++) {
				if (j != i)   a_sum += (A[i][j] * x[j]);
				
			}
			y[i] = (1 / A[i][i])*(b[i] - a_sum);
		}
		e = fabs(x[1] - y[1]);
		for (i = 1; i <= n; i++) {
			if (fabs(x[i] - y[i]) > e)
				e = fabs(x[i] - y[i]);
		}
		if (e < dert) {
			printf("k = %d\n",k);
			for (i = 1; i <= n; i++) {
				printf("y[%d] = %f\n", i, y[i]);
			}
			return 0;
		}
		else {
			for (i = 1; i <= n;i++) {
				x[i] = y[i];
			}
		}
	}
	printf("迭代%d次没有结果",N);
	return 0;
}

int main() {
	double A[7][7] = { {0,0,0,0,0,0,0},
					   {0,4,-1,0,-1,0,0},
					   {0,-1,4,-1,0,-1,0},
					   {0,0,-1,4,-1,0,-1},
					   {0,-1,0,-1,4,-1,0 },
					   {0,0,-1,0,-1,4,-1 },
					   {0,0,0,-1,0,-1,4 }};
	double b[7] = {0,0,5,-2,5,-2,6};
	int n = 6;
	double dert = 0.0001;
	int N = 1000;
	double x[7] = { 0,0,5,-2,5,-2,6 };
	double y[7];
	Jacobi(n,A,b,dert,N,x,y);
	system("pause");
	return 0;
}