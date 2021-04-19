#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> edge;
vector<bool> visited;
int computers, V, answer = 0;
int u, v;

void bfs(int cur)
{
    queue<int> q;
    visited[cur] = true;
    q.push(cur);
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
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
    cin >> computers >> V;
    edge.resize(computers + 1);
    visited.resize(computers + 1);

    for (int i = 0; i < V; i++)
    {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    bfs(1);

    for (int i = 1; i <= computers; i++)
    {
        if (visited[i])
            answer++;
    }

    cout << answer - 1 << "\n";
    return 0;
}