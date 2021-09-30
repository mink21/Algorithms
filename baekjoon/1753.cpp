#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9
using namespace std;

int V, E, start;
int u, v, w;
int dist[20001];
vector<pair<int, int>> edge[20001];

void readInput(void)
{
    cin >> V >> E >> start;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        edge[u].push_back(make_pair(v, w));
    }
    for (int i = 1; i <= V; i++)
    {
        dist[i] = INF;
    }
}

void dijkstra(void)
{
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push(make_pair(dist[start], start));

    while (!pq.empty())
    {
        int here = pq.top().second;
        int hereDist = -pq.top().first;
        pq.pop();

        if (hereDist > dist[here])
            continue;
        for (int i = 0; i < edge[here].size(); i++)
        {
            int there = edge[here][i].first;
            int nextDist = hereDist + edge[here][i].second;
            if (dist[there] > nextDist)
            {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    readInput();
    dijkstra();

    return 0;
}