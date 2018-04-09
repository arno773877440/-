#include <iostream>

using namespace std;
#define N 20
double a[N][N];
double x[N + 1];
double b[N + 1];
int n;//n����nδ֪����
int set()
{
	cout << "���������δ֪������ " << endl;
	cin >> n;
	int i, j;
	cout << "��������飨������� i��" << endl;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cin >> a[i][j];//ϵ��
		}
		cin >> b[i];//��
	}
	return 0;
}

int find(int k)//Ѱ�ҵ�k����Ԫ
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
void exchange(int i1, int i2)//�� i1 i2�л���
{
	int j;
	for (j = 1; j <= n; j++)
	{
		swap(a[i1][j], a[i2][j]);
	}
	swap(b[i1], b[i2]);
}
void div(int k)//�õ�k������ϵ��1
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
void eliminate(int k)//��Ԫ
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
void Gauss()//��˹��Ԫ
{
	int i, j, k;
	for (k = 1; k < n; k++)//������n - 1��Ԫ
	{
		int l = find(k);//Ѱ�ҵ�k��Ԫ��Ԫ��
		if (l != k)
		{
			exchange(l, k);
		}
		//��Ԫ
		div(k);
		eliminate(k);
		cout << "��" << k << "��Ԫ�᣺" << endl;
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
	cout << "��̣�" << endl;
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