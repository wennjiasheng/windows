#include<iostream>

using namespace std;

//左右指针法
void Swap(int *left, int *right)
{
	int * temp = left;
	left = right;
	right = temp;

}
int div(int *a, int left, int right)
{
	int k = right;
	while (left < right)
	{
		while (a[left] <= a[k] && left < right)
			left++;
		while (a[right] >= a[k] && left < right)
			right--;
		if (left<right)
			Swap(&a[left], &a[right]);
	}
	if (left != k)//在同一位置就不用交换了
		Swap(&a[left], &a[k]);
	return left;
}
void QuickSort(int *a, int left, int right)
{
	if (left > right)
		return;
	int ret = div(a, left, right);//与前序遍历类似
	QuickSort(a, left, ret - 1);
	QuickSort(a, ret + 1, right);
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, len - 1);
	for (int i = 0; i < len; i++)
		cout << arr[i];
	system("pause");
	return 0;
}