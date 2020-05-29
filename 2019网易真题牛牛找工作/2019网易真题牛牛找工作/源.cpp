#include<iostream>
#include<vector>
using namespace std;
int main()
{
	//O£¨n*m£©
	int N, M;
	cin >> N >> M;
	vector< int >D, P, A;
	D.resize(N);
	P.resize(N);
	A.resize(M);
	for (int i = 0; i < N; i++)
	{
		cin >> D[i] >> P[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> A[i];
		int count = 0;
		for (int j = 0; j < N; j++)
		{
			if (A[i] >= D[j])
			{
				if (count < P[j])
				{
					count = P[j];
				}
			}
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}