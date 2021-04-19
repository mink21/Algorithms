#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solve(vector<int> &v, int M)
{
	reverse(v.begin() + M, v.end());
	return next_permutation(v.begin(), v.end());
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, flag;
	vector<int> v;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		v.push_back(i);

	while (1)
	{
		flag = 1;
		for (int i = 0; i < M - 1; i++)
		{
			if (v[i] > v[i + 1])
				flag = 0;
		}
		if (flag == 1)
		{
			for (int i = 0; i < M; i++)
				cout << v[i] << " ";
			cout << "\n";
		}

		if (!solve(v, M))
			break;
	}
	return 0;
}