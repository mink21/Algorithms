#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 800+1;
const int INF = 1e9;

int n, e;
int a, b, c;
int v1, v2;
vector<pair<int,int>> graph[MAX];

void readInput(){
    cin>>n>>e;
    for(int i = 0; i<e; i++){
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    cin>>v1>>v2;

    // for(int i = 1; i<=n; i++){
    //     for(int j = 0; j<graph[i].size(); j++){
    //         cout<<i<< " "<< graph[i][j].first<<" "<< graph[i][j].second<<"\n";
    //     }
    // }
}

vector<int> dijkstra(int start, int end){
    vector<int> dist(end, INF);
    dist[start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(-dist[start], start));

    while(!pq.empty()){
        int here = pq.top().second;
        int hereDist = pq.top().first;
        pq.pop();

        if(hereDist>dist[here]){
            continue;
        }

        for(int i = 0; i<graph[here].size(); i++){
            int there = graph[here][i].first;
            int thereDist = hereDist + graph[here][i].second;

            if(thereDist < dist[there]){
                dist[there] = thereDist;
                pq.push(make_pair(-dist[there], there));
            }
        }
    }
    return dist;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    readInput();
  
    vector<int> result = dijkstra(1, n);
    vector<int> temp1 = dijkstra(v1, n);
    vector<int> temp2 = dijkstra(v2, n);

    for(int i = 1; i<result.size()+1; i++){
        cout<<result[i]<<" ";
    }
    cout<<"\n";

    int firstMethod = -result[v1] - temp1[v2] - temp2[n];
    int secondMethod = -result[v2] - temp2[v1] - temp1[n];

    //cout<<firstMethod<<" "<<secondMethod<<"\n";

    int ans = min(firstMethod, secondMethod);
    if(ans>=INF || ans<0){
        cout<<-1<<"\n";
    }else{
        cout<<ans<<"\n";
    }

    return 0;
}