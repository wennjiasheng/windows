#include<iostream>
#include<algorithm>
#include<string>

using namespace std;


string stringadd(string s1, string s2)
{
	 string b;
	 reverse(s1.begin(), s1.end());
	 reverse(s2.begin(), s2.end());
	 int fals = 0;
	 for (int i = 0; i < s1.size(); i++)
	 {	 
		 int temp = fals + s1[i] - '0' + s2[i] -'0';
		 if (temp >= 10)
		 {
			 b += temp - 10 + '0';
			 fals = 1;
		 }
		 else
		 {
			 b += temp + '0';
			 fals = 0;
		 }

	 }
	 for (int j = s1.size(); j < s2.size(); j++)
	 {
		 int temp = fals + s2[j] - '0';
		 if (temp >= 10)
		 {
			 b += temp - 10 + '0';
			 fals = 1;
		 }
		 else
		 {
			 b += temp + '0';
			 fals = 0;
		 }
	 }
	 if (fals == 1)
	 {
		 b += '1';
	 }
	 return b;
}
int main()
{
	string s1,s2;
	while (cin >> s1 >> s2)
	{
		string s3;
		if (s1.size() > s2.size())
		{
			s3 = stringadd(s2, s1);
		}
		else
		{
			s3 = stringadd(s1, s2);
		}
		reverse(s3.begin(), s3.end());
		cout << s3 << endl;
	}
	system("pause");
	return 0;
}
