#include<iostream>

using namespace std;

/*int main()
{
	double n, r;
	while (cin >> n >> r)
	{
		if (n > r * 2 * 3.14)
		{
			cout << "No" << endl;
		}
		else{
			cout << "Yes" << endl;
		}
	}
	return 0;
}*/

char *mystrstr(char *str, char *dec)
{
	while(*str)
	{
		char *q = dec;
		while (!(*str == *q)&&*str!='0')
		{
			str++;
		}
		char *p = str;
		while (*++str == *++q&&*str != '0'&&*dec!='0')
		{
		}
		if (!(*q) )
		{
			return p;
		}
	}
	return NULL;
}
int main()
{

	char *str = "bcd";
	char *dec = "abcdfffff";
	printf("%s", mystrstr(dec, str));
	system("pause");
	return 0;
}