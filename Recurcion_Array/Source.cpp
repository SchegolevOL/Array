/*I. ����������� ��������� ����������� ������� ��� ������ � ����������� ������������� ���������:
	1. ����� ��������
	2. ����� ���������
	3. ����� ����� ��������� �������
	4. ����� ������������ ��������� �������
	5. �������� ������� �������� � �������. ���������� true, ���� ������� � ������� ����, false � ���.
	6. ������ ������� �� �����
	7. ������� ���������� ������������� ��������� �������
	8. ������� ���������� ��������� �������� � ������
	9. ������� ���������� ������ ��������� � ������
	10. ������� ���������� ������������� ��������� � �������
	11. ������� ���������� �������� ��������� � �������*/

#include <iostream>
#include<Windows.h>
#include<time.h>
#include <stdlib.h>
using namespace std;

int SumArray(int* array, size_t length)//����� ����� ��������� �������
{
	return length == 0 ? 0 : *array + SumArray(array + 1, length - 1);
}

int Min(int* arr, int n) //����� ��������
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

int Max(int* arr, int n) //����� ���������
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

int MultipArray(int* array, size_t length)//����� ������������ ��������� �������
{
	return length == 0 ? 0 : *array * SumArray(array + 1, length - 1);
}

bool PresenceElement(int* arr, size_t n, int elem)//�������� ������� �������� � �������. ���������� true, ���� ������� � ������� ����, false � ���.
{
	if (elem == *arr)
		return 1;
	else
		if (n == 1)
			return 0;
	if (PresenceElement(arr + 1, n - 1, elem) == 1)
		return 1;
}

void PrintArray(int* arr, size_t n)//������ ������� �� �����
{
	cout << *arr << " ";
	if (n > 1)
		PrintArray(arr + 1, n - 1);
}

int NegativeQuantity(int* arr, size_t n)//������� ���������� ������������� ��������� �������
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

int PositiveQuantity(int* arr, size_t n)//������� ���������� ������������� ��������� � �������
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

int EvenQuantity(int* arr, size_t n)//������� ���������� ������ ��������� � �������
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

int OddQuantity(int* arr, size_t n)//������� ���������� �������� ��������� � �������
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

int OccurrencesElement(int* arr, size_t n, int elem)//������� ���������� ��������� �������� � ������
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