
#include "pch.h"
#include <iostream>

using namespace std;

void summa(double A, double B);
int* summa_min(double A, double B);
void prc(int *sum_min);
void difference(double A, double B);
void dif(int rez);

int main()
{
	//double A = 0.0000001, B = 0.0000101;
	double A = 1.1111010, B = 0.0000001; /// -6, 1
	//double A = 1.1100101, B = 0.0010010; /// -27, 18
	//double A = 1.1111101, B = 1.1111110; /// -3, -2
	//double A = 0.0000001, B = 1.1111110; /// 1, -2
	//double A = 1.1111100, B = 0.0000111; /// -4, 7
	//double A = 1.1110100, B = 0.0001010; /// -12, 10


	if (int(A) == 0 && int(B) == 0) summa(A, B);
	if (int(A) == 1 && int(B) == 1) prc(summa_min(A, B));
	if (int(A) == 1 && int(B) == 0 || int(A) == 0 && int(B) == 1) difference(A, B);

	return 0;
}

/// для положительных
void summa(double A, double B)
{
	int sum = (A + B) * 10000000;

	int rezult[8];
	for (int i = 7; i > -1; i--)
	{
		rezult[i] = sum % 10;
		sum /= 10;
	}

	for (int i = 7; i > -1; i--)
	{
		while (rezult[i] > 1)
		{
			rezult[i] -= 2;
			rezult[i - 1] += 1;
		}
	}

	for (int i = 0; i < 8; i++)
		cout << rezult[i];
}
/// для отрицательных
int* summa_min(double A, double B)
{
	int rezult = (A + B) * 10000000;
	//cout << rezult << endl;
	//if (rezult % 10 == 9) rezult -= 9;

	int *rez_arr = new int[8];
	for (int i = 7; i > -1; i--)
	{
		rez_arr[i] = rezult % 10;
		rezult /= 10;
	}

	for (int i = 7; i > -1; i--)
	{
		while (rez_arr[i] > 1)
		{
			rez_arr[i] -= 2;
			if (i - 1 == 0) break;
			rez_arr[i - 1] += 1;
		}
	}
	rez_arr[0] = 1;

	return rez_arr;
}
void prc(int *sum_min)
{
	int a = 0;

	for (int i = 1; i < 8; i++)
	{
		a = a * 10 + sum_min[i];
	}
	//cout << "\n a = " << a;
	a -= 1;
	//cout << "\n a = " << a;

	int *rezult = new int[8];
	for (int i = 7; i > -1; i--)
	{
		rezult[i] = a % 10;
		a /= 10;
	}

	for (int i = 0; i < 8; i++)
	{
		if (rezult[i] >= 1) rezult[i] = 0;
		else rezult[i] = 1;
	}
	rezult[0] = 1;

	//cout << "\n ----\n";
	for (int i = 0; i < 8; i++)
	{
		cout << rezult[i];
	}
	delete[] rezult;
}
/// положительный и отрицательный
void difference(double A, double B)
{
	int diff = (A + B) * 10000000;
	diff -= 1;
	//cout << diff << endl;
	int *rez = new int[8];
	for (int i = 7; i > -1; i--)
	{
		rez[i] = diff % 10;
		diff /= 10;
	}

	for (int i = 7; i > -1; i--)
	{
		while (rez[i] > 1)
		{
			if (rez[i] == 9) break;
			rez[i] -= 2;
			rez[i - 1] += 1;
		}
	}
	if (rez[0] == 0) dif((A+B) * 10000000);
	else
	{
		for (int i = 1; i < 8; i++)
		{
			if (rez[i] >= 1) rez[i] = 0;
			else if (rez[i] == 0) rez[i] = 1;
		}

		for (int i = 0; i < 8; i++)
			cout << rez[i];
	}
}
void dif(int rez)
{
	//cout << rez;

	int *dif = new int[8];
	for (int i = 7; i > -1; i--)
	{
		dif[i] = rez % 10;
		rez /= 10;
	}

	for (int i = 7; i > -1; i--)
	{
		while (dif[i] > 1)
		{
			dif[i] -= 2;
			dif[i - 1] += 1;
		}
	}

	for (int i = 0; i < 8; i++)
		cout << dif[i];
}