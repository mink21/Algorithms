#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> edge;
vector<bool> visited;
int num, M, answer = 0;
int u, v;

void dfs(int cur)
{
    visited[cur] = true;
    for (int i = 0; i < edge[cur].size(); i++)
    {
        int there = edge[cur][i];
        if (visited[there])
            continue;
        dfs(there);
    }
}

int main(void)
{
    cin >> num >> M;
    edge.resize(num + 1);
    visited.resize(num + 1);

    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    dfs(1);

    for (int i = 1; i <= num; i++)
    {
        if (visited[i])
            answer++;
    }

    cout << answer - 1 << endl;
    return 0;
}