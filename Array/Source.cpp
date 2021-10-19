/*�� ����� �++ �������� ��������� ������� ��� ������ � ������������� ���������, ��������� ���������:
1. ������ ������� �� �����
2. ����� ��������� �������
3. ������������ ��������� �������
4. ����� �������� � �������
5. ����� ��������� � �������
6. ������� �������������� ��������� �������
7. ����� ������� �������� � �������
8. ������� �������� � �������
9. ���������� ���������, ��������� ����� https://www.youtube.com/watch?v=lyZQPjUT5B4
10. ���������� ������� �������, ��������� ����� https://www.youtube.com/watch?v=Ns4TPTC8whw
11. ���������� �������� ���������, ��������� ����� https://www.youtube.com/watch?v=ROalU379l3U
12. ������� � ������
13. �������� �� �������
��� ������� ���������� ��������� ������ ������� main, �������� � �������� ������������ �������
��� � ������� new, ��� � � ������� malloc ��� ������ ������ �������. ��� �� ����������
��������� ������� ������ ��� ���� ��������� ��������.*/

#include <iostream>
#include<Windows.h>
#include<time.h>
#include <stdlib.h>

using namespace std;

void PrintArray(const int* arr, size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl;
}

int SumElement(const int* arr, size_t length)
{
	int sum = 0;
	for (size_t i = 0; i < length; i++)
	{
		sum += *(arr + i);
	}
	return sum;
}

int MultElement(const int* arr, size_t length)
{
	int mult = 1;
	for (size_t i = 0; i < length; i++)
	{
		mult *= *(arr + i);
	}
	return mult;
}

int MinElement(const int* arr, size_t length)
{
	int min = *(arr);
	for (size_t i = 1; i < length; i++)
	{
		if (min > *(arr + i))
		{
			min = *(arr + i);
		}
	}
	return min;
}

int MaxElement(const int* arr, size_t length)
{
	int max = *(arr);
	for (size_t i = 1; i < length; i++)
	{
		if (max < *(arr + i))
		{
			max = *(arr + i);
		}
	}
	return max;
}

double ArithmeticMean(const int* arr, size_t length)
{
	double arithmetic = SumElement(arr, length) / (double)length;
	return arithmetic;
}

int IndexElement(const int* arr, size_t length, int element)
{
	for (size_t i = 0; i < length; i++)
	{
		if (element == *(arr + i))
		{
			return i;
		}
	}
	return -1;
}

bool PresenceElement(const int* arr, size_t length, int element)
{
	bool pres = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (element == *(arr + i))
		{
			pres = 1;
		}
	}
	return pres;
}

void SelectionSort(int* array, size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		size_t minIndex = i;
		for (size_t j = i; j < length; j++)
			if (*(array + j) < *(array + minIndex))
				minIndex = j;
		int tmp = *(array + i);
		*(array + i) = *(array + minIndex);
		*(array + minIndex) = tmp;
	}
}

void ChangeSort(int* array, size_t length)
{
	int value;
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = i; j < length; j++)
			if (*(array + j) < *(array + i))
			{
				value = array[i];
				array[i] = array[j];
				array[j] = value;
			}
	}
}

void ChoiceSort(int* array, size_t length)
{
	int value;
	for (size_t i = 1; i < length; i++)
	{
		value = *(array + i);
		for (size_t j = i - 1; (j >= 0) && (value < *(array + j)); j--)
		{
			value = *(array + j + 1);
			*(array + j + 1) = *(array + j);
			*(array + j) = value;
		}
	}
}

void InsertElement(int* array, size_t length, size_t index, int element)
{
	for (size_t i = length - 1; i > index; i--)
	{
		*(array + i) = *(array + i - 1);
	}
	*(array + index) = element;
}

void DeleteElement(int* array, size_t length, size_t index)
{
	for (size_t i = index; i < length - 1; i++)
	{
		*(array + i) = *(array + i + 1);
	}
}

void RandArray(int* Array, int length, int begin, int end)
{
	for (size_t i = 0; i < length; i++)
		*(Array + i) = rand() % (end - begin + 1) + begin;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	size_t size;

	cout << "������� ������ ������� : ";
	cin >> size;
	int* array = new int[size];
	RandArray(array, size, 1, 10);

	PrintArray(array, size);
	cout << endl;

	cout << "����� ��������� ������� = " << SumElement(array, size) << endl;
	cout << "������������ ��������� ������� = " << MultElement(array, size) << endl;
	cout << "����������� ������� ������� = " << MinElement(array, size) << endl;
	cout << "������������ ������� ������� = " << MaxElement(array, size) << endl;
	cout << "������� �������������� ��������� �������  = " << ArithmeticMean(array, size) << endl;

	cout << "������ �������� \"5\" � ������� = ";
	if (IndexElement(array, size, 5) >= 0)
		cout << IndexElement(array, size, 5) << endl;
	else
		cout << "�������� ���" << endl;


	cout << "������� �������� \"5\" � ������� = ";
	if (PresenceElement(array, size, 5))
		cout << "������� ����" << endl;
	else
		cout << "�������� ���" << endl;

	RandArray(array, size, 10, 99);
	PrintArray(array, size);
	cout << endl;
	SelectionSort(array, size);
	PrintArray(array, size);
	cout << endl;
	RandArray(array, size, 10, 99);
	PrintArray(array, size);
	cout << endl;
	ChangeSort(array, size);
	PrintArray(array, size);
	cout << endl;
	RandArray(array, size, 10, 99);
	PrintArray(array, size);
	cout << endl;
	ChoiceSort(array, size);
	PrintArray(array, size);
	cout << endl;

	DeleteElement(array, size, 1);
	PrintArray(array, size);
	cout << endl;

	InsertElement(array, size, 3, 5);
	PrintArray(array, size);
	cout << endl;

	delete[] array;
	return 0;
}