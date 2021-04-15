#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
int N;
int u, v;
int parent[100001];

void dfs(int cur)
{
    visited[cur] = true;
    for (int i = 0; i < tree[cur].size(); i++)
    {
        int there = tree[cur][i];
        if (!visited[there])
        {
            parent[there] = cur;
            dfs(there);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    tree.resize(N + 1);
    visited.resize(N + 1);
    for (int i = 0; i < N - 1; i++)
    {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    dfs(1);

    for (int i = 2; i < N; i++)
    {
        cout << parent[i] << "\n";
    }
    return 0;
}