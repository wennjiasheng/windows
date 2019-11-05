#include<iostream>
#include<stdlib.h>

using namespace std;



int main()
{
	int array[10][10];
	int i, j;
	for (i = 0; i<10; i++)
	{
		for (j = 0; j<10; j++)
		{
			array[i][j] = 0; 
		}
	}


	for (i = 0; i<10; i++)
	{
		for (j = 0; j<10; j++)
		{
			if (j == 0)
			{
				array[i][j] = 1; 
			}
		}
	}


	for (i = 0; i<10; i++)
	{
		for (j = 0; j<10; j++)
		{
			if (j>0 && i>0 && j <= i) 
			{
				array[i][j] = array[i - 1][j - 1] + array[i - 1][j]; 
			}
		}
	}


	for (i = 0; i<10; i++)
	{
		for (j = 0; j <= i; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}


