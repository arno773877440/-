//#include<stdio.h>
//#include<windows.h>
//#define N 20
//double a[N][N];		//系数矩阵
//double x[N + 1];	//结果矩阵
//double b[N + 1];	//增广矩阵
//int n;	//未知数个数
//
//int find(int k){		//寻找第k列主元
//	int i, tag = k;
//	double maxv = 0;
//	for (i = k; i <= n; i++){
//		if (a[i][k] > maxv){
//			maxv = a[i][k];
//			tag = i;
//		}
//	}
//	return tag;
//}
//void exchange(int i1, int i2){		//交换两行
//	int j;
//	double temp;
//	for (j = 1; j <= n; j++){
//		temp = a[i1][j];
//		a[i1][j] = a[i2][j];
//		a[i2][j] = temp;
//	}
//	temp = b[i1];
//	b[i1] = b[i2];
//	b[i2] = temp;
//}
//void div(int k){		//k行首项系数为1
//	double temp = a[k][k];
//	for (int j = k; j <= n; j++) {
//		a[k][j] /= temp;
//	}
//	b[k] /= temp;
//}
//
//void eliminate(int k){		//消元
//	int i, j;
//	double t;
//	for (i = k + 1; i <= n; i++){
//		t = a[i][k] / a[k][k];
//		for (j = k; j <= n; j++){
//			a[i][j] -= a[k][j] * t;
//		}
//		b[i] -= b[k] * t;
//	}
//}
//void Gauss(){		//高斯消元
//	int i, j, k;
//	for (k = 1; k < n; k++){
//		int l = find(k);
//		if (l != k){
//			exchange(l, k);
//		}
//		div(k);
//		eliminate(k);
//	}
//	div(k);
//	x[k] = b[k];
//	for (i = n - 1; i >= 1; i--){
//		for (j = i + 1; j <= n; j++){
//			b[i] -= a[i][j] * b[j];
//		}
//		x[i] = b[i];
//	}
//}
//
//int main(){
//	int i, j;
//	n = 4;
//	double arr[4][4] = { { 1.1348, 3.8326, 1.1651, 3.4017 },
//						{ 0.5301,1.7875,2.5330,1.5435 },
//						{ 3.4129,4.9317,8.7643,1.3142 },
//						{ 1.2371,4.9998,10.6721,0.0147 } };
//	double brr[4] = { 9.5342,6.3941,18.4231,16.9237 };
//	for (i = 1; i <= 4; i++) {
//		for (j = 1; j <= 4; j++) {
//			a[i][j] = arr[i-1][j-1];
//		}
//	}
//	for (i = 1; i <= 4; i++) {
//		b[i] = brr[i-1];
//	}
//
//	Gauss();
//	for (i = 1; i <= 4; i++) {
//		printf("x[%d] = %f\n",i,x[i]);
//	}
//	system("pause");
//	return 0;
//}