#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class sulution
{
public:
	int gitmaxvalu(int m, vector<int> a, vector<int> v)
	{
		if (a.size() == 0 || m == 0 || v.size() == 0)
		{
			return 0;
		}
		int M = m + 1;
		int N = a.size() + 1;
		vector<vector<int> > result;
		result.resize(N);
		for (int i = 0; i != N; ++i) {
			result[i].resize(M, 0);
		}
		for (int i = 0; i != N; ++i) {
			for (int j = M - 1; j > 0; --j) {
				if (a[i - 1] > j) {
					result[i][j] = result[i - 1][j];
				}
				else {
					int newValue = result[i - 1][j - a[i - 1]] + v[i - 1];
					result[i][j] = max(newValue, result[i - 1][j]);
				}
			}
		}
		return result[N-1][m];
	}
};
int main()
{
	vector<int> a;
	a = { 2, 4, 5, 6 };
	vector<int> v;
	v = { 1, 2, 3, 4 };
	int m = 5;
	sulution s;
	cout << s.gitmaxvalu(m, a, v) << endl;
	system("pause");
	return 0;
}