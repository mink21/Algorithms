#include <iostream>
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

void solve(void){
    int n;
    int graph[125][125];
    int dist[125][125];
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    cin>>n;
    for(int i = 0; i<n; i++){
        for(int j =0; j<n; j++){
            cin>>graph[i][j];
        }
    }

    for(int i = 0; i<n; i++){
        fill(dist[i], dist[i]+125, INF);
    }

    int x = 0, y = 0;
    priority_queue<pair<int, pair<int, int> > > pq;
    pq.push({-graph[x][y], {0,0}});
    dist[x][y] = graph[x][y];

    while(!pq.empty()){
        int distance = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if(dist[x][y] <distance) continue;
        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>= n) continue;
            int cost = distance + graph[nx][ny];
            if(cost <dist[nx][ny]){
                dist[nx][ny] = cost;
                pq.push({-cost, {nx, ny}});
            }
        }
    }
    cout<<dist[n-1][n-1] <<"\n";
}

int main(void){
    int test_case;
    cin>>test_case;
    for(int i = 0; i<test_case;i++)
        solve();
    return 0;
}
