#include <iostream>

using namespace std;
#define N 20
double a[N][N];
double x[N + 1];
double b[N + 1];
int n;//n程数n未知数数
int set()
{
	cout << "请输入程数未知数数： " << endl;
	cin >> n;
	int i, j;
	cout << "请输入程组（逐输入程 i）" << endl;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cin >> a[i][j];//系数
		}
		cin >> b[i];//结
	}
	return 0;
}

int find(int k)//寻找第k列主元
{
	int i, tag = k;
	double maxv = 0;
	for (i = k; i <= n; i++)
	{
		if (a[i][k] > maxv)
		{
			maxv = a[i][k];
			tag = i;
		}
	}
	return tag;
}
void exchange(int i1, int i2)//第 i1 i2行互换
{
	int j;
	for (j = 1; j <= n; j++)
	{
		swap(a[i1][j], a[i2][j]);
	}
	swap(b[i1], b[i2]);
}
void div(int k)//让第k程首项系数1
{
	double temp = a[k][k];
	for (int j = k; j <= n; j++)
	{
		a[k][j] /= temp;
	}
	b[k] /= temp;
}
void disME(int k)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = i; j <= n; j++)
		{
			if (a[i][j])
			{
				if (a[i][j] == 1)
				{
					if (j == n)
						cout << "x" << j;
					else
						cout << "x" << j << " + ";
				}
				else
				{
					if (j == n)
						cout << a[i][j] << "x" << j;
					else
						cout << a[i][j] << "x" << j << " + ";
				}
			}
		}
		cout << " = " << b[i] << endl;
	}
	system("pause");
}
void eliminate(int k)//消元
{
	int i, j;
	double t;
	for (i = k + 1; i <= n; i++)
	{
		t = a[i][k] / a[k][k];
		for (j = k; j <= n; j++)
		{
			a[i][j] -= a[k][j] * t;
		}
		b[i] -= b[k] * t;
	}
}
void Gauss()//高斯消元
{
	int i, j, k;
	for (k = 1; k < n; k++)//共进行n - 1消元
	{
		int l = find(k);//寻找第k消元主元程
		if (l != k)
		{
			exchange(l, k);
		}
		//消元
		div(k);
		eliminate(k);
		cout << "第" << k << "消元结：" << endl;
		//disME(k);
	}
	div(k);
	x[k] = b[k];
	//disM();
	for (i = n - 1; i >= 1; i--)
	{
		for (j = i + 1; j <= n; j++)
		{
			b[i] -= a[i][j] * b[j];
		}
		x[i] = b[i];
	}
}
void dis()
{
	int i;
	cout << "解程：" << endl;
	for (i = 1; i <= n; i++)
	{
		cout << "x" << i << "  =  ";
		printf("%.5f\n", x[i]);
	}
}
int main()
{
	set();
	Gauss();
	dis();
	system("pause");
	return 0;
}