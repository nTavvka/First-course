
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

void solve_sum(string A, string B);
int* add_one(int *rezult, int &rez_size);
void solve_diff(string A, string B);
string point(string A, int counter);
int cmp(string A, string B);

int main()
{
	//string signA = "+", signB = "+";
	//string A = "1D4A", B = "11E";

	string signA = "+", signB = "+";
	string A = "34", B = "26";

	/*string signA = "+", signB = "+";
	string A = "BD", B = "BD";*/

	if (signA == signB) solve_sum(A, B);

	if (signA == "+" && signB == "-")
	{
		if (cmp(A, B) == 0 || cmp(A, B) == 2) solve_diff(A, B);
		else if (cmp(A, B) == 1)
		{
			cout << "-";
			solve_diff(B, A);
		}
	}
	else if (signA != signB && cmp(A, B) == 2) return 0;
	else if (signA == "-" && signB == "+")
	{
		if (cmp(A, B) == 1 || cmp(A, B) == 2) solve_diff(B, A);
		else if (cmp(A, B) == 0)
		{
			cout << "-";
			solve_diff(A, B);
		}
	}
	return 0;
}

void solve_sum(string A, string B)
{
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	int size = 0;

	int rez_size = 1;
	int *rezult = new int[rez_size];
	rezult[0] = 0;

	if (A.size() >= B.size()) size = A.size();
	else size = B.size();

	int counter = 0;
	for (int i = 0, a = 0; i < size; i++, a = 0, counter = 0)
	{
		/// буква с буквой
		if (A[i] >= 'A' && B[i] >= 'A')
			a = A[i] + B[i] - 'A' - 'A' + 20;
		/// цифра с цифрой 
		if (A[i] < 58 && B[i] < 58)
			a = A[i] + B[i] - '0' - '0';
		/// буква с цифрой
		if (A[i] >= 'A' && B[i] < 58 || A[i] < 58 && B[i] >= 'A')
			a = A[i] + B[i] - 'A' - '0' + 10;
		/// буква и 0
		if (A[i] >= 'A' && B[i] == 0)
			a = A[i] - 'A' + 10;
		else if (B[i] >= 'A' && A[i] == 0)
			a = B[i] - 'A' + 10;
		/// цифра и 0
		if (A[i] < 58 && B[i] == 0)
			a = A[i] - '0';
		else if (B[i] < 58 && A[i] == 0)
			a = B[i] - '0';

		rezult[rez_size - 1] += a;
		while (true)
		{
			if (rezult[rez_size - 1] > 14)
			{
				counter++;
				rezult[rez_size - 1] -= 15;
				rezult = add_one(rezult, rez_size);
				rezult[rez_size - 1] += 1;
			}
			else break;
		}
		if (counter == 0 && (i + 1) < size) rezult = add_one(rezult, rez_size);
	}

	string sum = "";
	for (int i = rez_size - 1; i > -1; i--)
	{
		if (rezult[i] < 10) sum += rezult[i] + '0';
		else sum += rezult[i] + 'A' - 10;
	}
	cout << sum;
	delete[] rezult;
}
int* add_one(int *rezult, int &rez_size)
{
	rez_size++;
	int *temp = new int[rez_size];

	for (int i = 0; i < rez_size - 1; i++)
		temp[i] = rezult[i];
	delete[] rezult;

	rezult = temp;
	rezult[rez_size - 1] = 0;

	return rezult;
}
void solve_diff(string A, string B)
{
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	int size = 0;

	int rez_size = 1;
	int *rezult = new int[rez_size];
	rezult[0] = 0;

	if (A.size() >= B.size()) size = A.size();
	else size = B.size();

	int a = 0;
	for (int i = 0; i < size; i++, a = 0)
	{
		/// буква и буква
		if (A[i] >= 'A' && B[i] >= 'A')
		{
			if (A[i] < B[i]) A = point(A, i);
			a = A[i] - B[i];
			//else if (A[i] < B[i])

		}
		/// буква и 0
		else if (A[i] >= 'A' && B[i] == 0)
			a = A[i] - 'A' + 10;
		/// буква и цифра
		else if (A[i] >= 'A' && B[i] < 58 && B[i] >= '0')
			a = A[i] - 'A' + 10 - B[i] + '0';
		/// цифра и цифра
		else if (A[i] < 58 && B[i] < 58 && B[i] >= '0')
		{
			if (A[i] < B[i]) A = point(A, i);
			a = A[i] - B[i];
		}
		/// цифра и 0
		else if (A[i] < 58 && B[i] == 0)
		{
			a = A[i] - '0';
		}

		rezult[rez_size - 1] = a;
		//cout << A << endl;
		if (i + 1 < size) rezult = add_one(rezult, rez_size);
	}

	string diff = "";
	for (int i = rez_size - 1; i > -1; i--)
	{
		if (rezult[i] < 10) diff += rezult[i] + '0';
		else diff += rezult[i] + 'A' - 10;
	}
	//reverse(diff.begin(), diff.end());
	cout << diff;
	delete[] rezult;
}
string point(string A, int counter)
{
	if (A[counter + 1] != 'A')
	{
		A[counter + 1] -= 1;
		A[counter] += 15;
	}
	else if (A[counter + 1] == 'A')
	{
		A[counter + 1] = '9';
		if (A[counter] == 9) A[counter] = 'A';
		else A[counter] += 15;
	}
	return A;
}
int cmp(string A, string B)
{
	int counterA = 0;
	for (int i = 0; i < A.size(); i++)
		if (A[i] < 58) counterA += (A[i] - '0') * pow(10, A.size() - 1 - i);
		else counterA += (A[i] - 'A' + 10) * pow(10, A.size() - 1 - i);

	int counterB = 0;
	for (int i = 0; i < B.size(); i++)
		if (B[i] < 58) counterB += (B[i] - '0') * pow(10, B.size() - 1 - i);
		else counterB += (B[i] - 'A' + 10) * pow(10, B.size() - 1 - i);

	//cout << "\n A = " << counterA << "\n B = " << counterB << endl;
	if (counterA > counterB) return 0;
	if (counterA < counterB) return 1;
	if (counterA == counterB) return 2;
}