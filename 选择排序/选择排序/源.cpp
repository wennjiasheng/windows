#include<iostream>
using namespace std;

void SelectSort(int* array, int size)//—°‘Ò≈≈–Ú
{
	int i = 0;
	int j = 0;
	int min = 0;
	for (i = 0; i < 10; i++)
	{
		min = i;
		for (j = 0; j < 10; j++)
		{
			if (array[min] < array[j])
			{
				int temp = array[j];
				array[j] = array[min];
				array[min] = temp;
			}
		}

	}
}


int main()
{
	int arr[]={ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(arr) / sizeof(int);
	SelectSort(arr, len);
	for (int i = 0; i < len; i++)
	{
		cout << arr[i];
	}
	system("pause");
	return 0;
}