/*I. Реализовать следующие рекурсивные функции для работы с одномерными динамическими массивами:
	1. Поиск минимума
	2. Поиск максимума
	3. Поиск суммы элементов массива
	4. Поиск произведения элементов массива
	5. Проверка наличия элемента в массиве. Возвращает true, если элемент в массиве есть, false – нет.
	6. Печать массива на экран
	7. Подсчёт количества отрицательных элементов массива
	8. Подсчёт количества вхождений элемента в массив
	9. Подсчёт количества чётных элементов в массив
	10. Подсчёт количества положительных элементов в массиве
	11. Подсчёт количества нечётных элементов в массиве*/

#include <iostream>
#include<Windows.h>
#include<time.h>
#include <stdlib.h>
using namespace std;

int SumArray(int* array, size_t length)//Поиск суммы элементов массива
{
	return length == 0 ? 0 : *array + SumArray(array + 1, length - 1);
}

int Min(int* arr, int n) //Поиск минимума
{

	if (n == 1)
		return *arr;
	else
	{
		int min = Min(arr + 1, n - 1);
		if (*arr > min)
			return min;
		else
			return *arr;
	}
}

int Max(int* arr, int n) //Поиск максимума
{

	if (n == 1)
		return *arr;
	else
	{
		int max = Max(arr + 1, n - 1);
		if (*arr < max)
			return max;
		else
			return *arr;
	}
}

int MultipArray(int* array, size_t length)//Поиск произведения элементов массива
{
	return length == 0 ? 0 : *array * SumArray(array + 1, length - 1);
}

bool PresenceElement(int* arr, size_t n, int elem)//Проверка наличия элемента в массиве. Возвращает true, если элемент в массиве есть, false – нет.
{
	if (elem == *arr)
		return 1;
	else
		if (n == 1)
			return 0;
	if (PresenceElement(arr + 1, n - 1, elem) == 1)
		return 1;
}

void PrintArray(int* arr, size_t n)//Печать массива на экран
{
	cout << *arr << " ";
	if (n > 1)
		PrintArray(arr + 1, n - 1);
}

int NegativeQuantity(int* arr, size_t n)//Подсчёт количества отрицательных элементов массива
{
	int neg;

	if (*arr < 0)
		neg = 1;
	else
		neg = 0;
	if (n == 1)
		return neg;
	else
		neg = neg + NegativeQuantity(arr + 1, n - 1);
}

int PositiveQuantity(int* arr, size_t n)//Подсчёт количества положительных элементов в массиве
{
	int pos;

	if (*arr >= 0)
		pos = 1;
	else
		pos = 0;
	if (n == 1)
		return pos;
	else
		pos = pos + PositiveQuantity(arr + 1, n - 1);
}

int EvenQuantity(int* arr, size_t n)//Подсчёт количества чётных элементов в массиве
{
	int eve;

	if (*arr % 2 == 0)
		eve = 1;
	else
		eve = 0;
	if (n == 1)
		return eve;
	else
		eve = eve + EvenQuantity(arr + 1, n - 1);
}

int OddQuantity(int* arr, size_t n)//Подсчёт количества нечётных элементов в массиве
{
	int eve;

	if (*arr % 2 != 0)
		eve = 1;
	else
		eve = 0;
	if (n == 1)
		return eve;
	else
		eve = eve + EvenQuantity(arr + 1, n - 1);
}

int OccurrencesElement(int* arr, size_t n, int elem)//Подсчёт количества вхождений элемента в массив
{
	int occ;
	if (elem == *arr)
		occ = 1;
	else
		occ = 0;
	if (n == 1)
		return occ;
	else
		occ = occ + OccurrencesElement(arr + 1, n - 1, elem);
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	size_t size = 5;

	int* array = new int[size];
	array[0] = -1;
	array[1] = -3;
	array[2] = -1;
	array[3] = -1;
	array[4] = -5;

	cout << Min(array, size) << endl;
	cout << Max(array, size) << endl;
	cout << PresenceElement(array, size, 0) << endl;
	PrintArray(array, size);
	cout << endl;
	cout << NegativeQuantity(array, size) << endl;
	cout << PositiveQuantity(array, size) << endl;
	cout << EvenQuantity(array, size) << endl;
	cout << OddQuantity(array, size) << endl;
	cout << OccurrencesElement(array, size, -1) << endl;
	cout << SumArray(array, size) << endl;
	cout << MultipArray(array, size) << endl;

	delete[] array;
	return 0;
}