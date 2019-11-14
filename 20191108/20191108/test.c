#include<iostream>


using namespace std;


int main()
{
	char *str1;
	cin >> str1;
	int ret = strlen(str1);
	string p,q;
	int count1 = 1;
	int count2 = 0;
	for (int i = 0; i < ret-1; i++)
	{
		
		if ((str1[i + 1] - str1[i]) == 1)
		{
			p += str1[i];
			count1++;
		}
		if ((str1[i + 1] - str1[i]) != 1)
		{
			if (count1>=count2)
			{
				q = p;
				p = 0;
			}
			else
			{
				p = 0;
				count1 = 1;
			}
		}
		cout << q << endl;
	}
	return 0;
}