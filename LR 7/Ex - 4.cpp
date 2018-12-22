
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

string sum(string A, string B);
string raz(string A, string B);

int main()
{
	char signA = '+', signB = '-';
	string A = "BD", B = "BD";
		
	if (signA == '+' && signB == '+')
		cout << sum(A, B);
	else if (signA != signB && A == B)
		cout << 0 << endl;
	else if (signA == '-' && A > B && signB == '+')
		cout << "-" << raz(A, B);
	else if (signA == '-' && signB == '-')
		cout << "-" << sum(A, B);
	else if (signA == '+' && signB == '-' && A > B)
		cout << raz(A, B);
	else if (signA = '+' && signB == '-' && A < B)
		cout << "-" << raz(B, A);

	return 0;
}

string sum(string A, string B)
{
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	int size;
	if (A.size() < B.size()) size = B.size() + 1;
	else size = A.size() + 1;

	string sum = "";
	int n = size, s = size - 1;

	for (int i = 0, a = 0; i < s; i++)
	{
		if (A[i] > 64 && B[i] > 64)                                                          /// оба - буквы
			a = A[i] + B[i] - 110 + a;
		else if (A[i] > 47 && A[i] < 58 && B[i] > 47 && B[i] < 58)                           /// оба - цифры
			a = A[i] + B[i] - 96 + a;
		else if (A[i] > 47 && A[i] < 58 && B[i] > 64 || B[i] > 47 && B[i] < 58 && A[i] > 64) /// один - цифра, другой буква
			a = A[i] + B[i] - 103 + a;
		else if (A[i] > 47 && A[i] < 58 || B[i] > 47 && B[i] < 58)                           /// один - цифра, одного нет
			a = A[i] + B[i] - 48 + a;
		else if (A[i] > 64 || B[i] > 64)                                                     /// один - буква, одного нет
			a = A[i] + B[i] - 55 + a;
   	///cout << a << endl;
		if (a < 10)
			sum += a + '0';
		else if (a > 9 && a < 15)
			sum += a + 55;

		if (a > 14)
		{
			sum += a / 15 + 48;

			if (a % 15 > 9)
			{
				sum += a % 15 + 'A' - 10;
				continue;
			}
			else if (a % 15 < 10)
			{
				sum += a % 15 + '0';
				continue;
			}

			if (A[i + 1] > 47 || B[i + 1] > 47)
				a = a / 15;
			else a = 0;
			//cout << a << endl;
		}
		//a = 0;
		//cout << a;
	}

	if (sum[0] > 60) reverse(sum.begin(), sum.end());
	//cout << "\n sum = " << sum << endl;
	return sum;
}

string raz(string A, string B)
{
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	int size;
	if (A.size() < B.size()) size = B.size() + 1;
	else size = A.size() + 1;

	string raz = "";
	int n = size, s = size - 1;
	int b = 0;
	for (int i = 0, a = 0; i < s; i++)
	{
		if (A[i] < B[i] && A[i] < 58 && B[i] < 58)    
		{
			a += 15;
			b = A[i + 1] - 56;
			if (b > 9) A[i + 1] = b + 55;
			if (b < 10 && b > -1) A[i + 1] = b + 48;
		}
   /// цифра - цифра
		if (A[i] < B[i] && A[i] > 58 && B[i] < 58)    
		{
			a += -6;
			b = A[i + 1] - 56;
			if (b > 9) A[i + 1] = b + 55;
			if (b < 10 && b > -1) A[i + 1] = b + 48;
		} 
   ///  буква - цифра
		if (A[i] > 64 && B[i] > 64)                                                          /// оба - буквы
			a = A[i] - B[i] + a;
		else if (A[i] > 47 && A[i] < 58 && B[i] > 47 && B[i] < 58)                           /// оба - цифры
			a = A[i] - B[i] + a;
		else if (A[i] > 47 && A[i] < 58 && B[i] > 64 || B[i] > 47 && B[i] < 58 && A[i] > 64) /// один - цифра, другой буква
			a = (A[i] - 55) - (B[i] - 48) + a;
		else if (A[i] > 47 && A[i] < 58 || B[i] > 47 && B[i] < 58)                           /// один - цифра, одного нет
			a = A[i] - B[i] - 48 + a;
		else if (A[i] > 64 || B[i] > 64)                                                     /// один - буква, одного нет
			a = A[i] - B[i] - 55 + a;

		if (a < 10)
			raz += a + '0';
		else if (a > 9 && a < 15)
			raz += a + 'A' - 10;

		if (a > 14)
		{
			raz += a / 15 + 48;

			if (a % 15 > 9)
			{
				raz += a % 15 + 'A' - 10;
				continue;
			}
			else if (a % 15 < 10)
			{
				raz += a % 15 + '0';
				continue;
			}

			if (A[i + 1] > 47 || B[i + 1] > 47)
				a = a / 15;
			else a = 0;
		}
		//a = 0;
	}
	reverse(raz.begin(), raz.end());
	//cout << "\n raz = " << raz << endl;
	return raz;
}