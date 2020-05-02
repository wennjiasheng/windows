#include<iostream>
using namespace std;

int func(int x){
	int count = 0; 
	while (x) 
	{
		count++;
		x = x&(x - 1);//ÓëÔËËã 
	}
	return count;
}
int main()
{
	int a = 9999;
	cout << func(9999) << endl;
}