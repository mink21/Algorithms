#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector<vector<int>> edge;
vector<bool> visited;
int N, M, V;
int u, v;

void dfs(int cur)
{
    visited[cur] = true;
    cout << cur << " ";
    for (int i = 0; i < edge[cur].size(); i++)
    {
        int there = edge[cur][i];
        if (visited[there])
            continue;
        dfs(there);
    }
}

void bfs(int cur)
{
    queue<int> q;
    visited[cur] = true;
    q.push(cur);
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        cout << here << " ";
        for (int i = 0; i < edge[here].size(); i++)
        {
            int there = edge[here][i];
            if (visited[there])
                continue;
            visited[there] = true;
            q.push(there);
        }
    }
}

int main(void)
{
    cin >> N >> M >> V;
    edge.resize(N + 1);
    visited.resize(N + 1);
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i = 1; i <= N; i++)
    {
        sort(edge[i].begin(), edge[i].end());
    }

    dfs(V);
    cout << endl;
    for (int i = 0; i < N + 1; i++)
    {
        visited[i] = false;
    }
    bfs(V);
    cout << endl;
    return 0;
}