#include<iostream>

using namespace std;


//直接插入排序
//将无序序列元素一个个插入到已经排好顺序的不
void Insertsort(int *a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int temp = a[i];
		int j;
		for ( j = i-1; a[j] > temp; j--)
		{
			a[j + 1] = a[j];
		}
		a[j+1] = temp;
	}
}
int main()
{
	int a[10] = { 1, 3, 5, 6, 4, 3, 8, 9, 0, 10 };
	
	Insertsort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i]<<' ' ;
	}

	system("pause");
	return 0;
}