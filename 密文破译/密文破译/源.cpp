#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		//v w x y z
		
		for (int i = 0; i < str.size(); i++)
		{
			if ( 'F' <= str[i]  && str[i]<= 'Z')
			{
				str[i] = str[i] - 5;
				continue;
			}
			if ('A' <= str[i] && str[i] <= 'E')
			{
				str[i] = str[i] + 21;
			}
		}
		cout <<str<< endl;
	}
	return 0;
}