#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dfs(vector<int>& v, int M)
{
	reverse(v.begin() + M, v.end());
	return next_permutation(v.begin(), v.end());
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	vector<int> v;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		v.push_back(i);

	while (1)
	{
		for (int i = 0; i < M; i++)
			printf("%d ", v[i]);
		printf("\n");

		if (!dfs(v, M))
			break;
	}
	return 0;
}