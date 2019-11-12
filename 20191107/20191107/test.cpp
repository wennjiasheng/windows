#include<iostream>


using namespace std;


int main()
{ 
	int n;
	while (cin >> n)
	{
		char *p = { 0 };
		cin >> p;
		int ret = strlen(p);
		string s, ss;
		for (int i = 0; i < ret; i++)
		{
			if (p[i] >= 0 && p[i] <= 9)
			{
				s.push_back(p[i]);
			}
			if (s.length()>ss.length ())
			{
				ss = s;
				s.erase();
			}

		}
		for (int i = 0; i < ss.length(); i++)
		{
			cout << ss[i]<<endl;
		}
	}

	return 0;
}