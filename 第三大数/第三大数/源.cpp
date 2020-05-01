#include<iostream>
using namespace std;
int findthirdbig(int arr[], int length)
{
	if (length <= 2)
	{
		return arr[0] > arr[1] ? arr[0] : arr[1];
	}
	if (arr[2] > arr[1])
	{
		int temp = arr[2];
		arr[2] = arr[1];
		arr[1] = temp;
	}
	if (arr[1] > arr[0])
	{
		int temp = arr[1];
		arr[1] = arr[0];
		arr[0] = temp;
	}
	for (int i = 2; i < length; i++)
	{
		if (arr[i]>arr[0])
		{
			arr[2] = arr[1];
			arr[1]= arr[0];
			arr[0] = arr[i];
		}
	}
	if (arr[0]>arr[1]&&arr[1]>arr[2])
		return arr[2];
	else
	{
		return arr[0];
	}
}
int main()
{
	int arr[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int arr1[] = { 1, 2, 3, 4, 5, 6, 7 };
	cout << findthirdbig(arr1, sizeof(arr1) / sizeof(arr1[0])) << endl;
	cout << findthirdbig(arr, sizeof(arr) / sizeof(arr[0])) << endl;
	system("pause");
	return 0;
}