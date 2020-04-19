#include<stdio.h>
#include<iostream>
using namespace std;
void getonce(int a[], int n){
	int result = 0, count = 1;
	for (int i = 0; i < n; i++){
		result ^= a[i];
	}
	if (result == 0){
		cout << "数组里没有只出现一次的元素" << endl;
		return;
	}
	cout << "result=" << result << endl; //测试所有的异或结果
	while (result != 0){
		if (result && 1 == 1)  //找出第一次出现1的位数
			break;
		else{
			result >>= 1;
			count <<= 1;
		}
	}
	cout << "count=" << count << endl;//测试从低位到高位第一次出现1的位数
	int first = 0;
	int second = 0;
	for (int j = 0; j < n; j++){
		if ((a[j] & count) == 0){
			first ^= a[j];
			cout << "firstgroup=" << a[j] << " "; //测试第一组的结果 
		}
		else{
			second ^= a[j];
			cout << "secondgroup=" << a[j] << " ";//测试第二组的结果
		}
	}
	cout << endl;
	if (((first | 0) != 0) && (second | 0 != 0)){
		cout << "first=" << first << endl;
		cout << "second=" << second << endl;
	}
	else if ((first | 0) != 0){
		cout << "数组只有一个元素不同" << endl;
		cout << first << endl;
	}
	else{
		cout << "数组只有一个元素不同" << endl;
		cout << second << endl;
	}
}

int main(){
	int a[] = { 23, 23, 23, 78, 23, 78 };
	int b[] = { 1, 1, 4, 1, 1, 1 };
	getonce(a, 6);
	getonce(b, 6); 
	system("pause");

	return 0;
}
