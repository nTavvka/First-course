// DOP - 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int A = 47;
	int arr[3] = { 5, 47, 89 };

	for (int i = 0, rez = 0; i < 3; i++, rez = 0)
	{
		while (rez < A)
			rez += arr[i];
	
		if (rez == A) cout << "\n делится - " << arr[i];
		else cout << "\n не делится - " << arr[i];
	}
}