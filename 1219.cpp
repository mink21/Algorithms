#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> a[100];
bool visited[100];
int test_case, T = 10, N;

void init(){
    for(int i = 0; i<100; i++){
        visited[i] = false;
        a[i].clear();
    }
    cin>>test_case>>N;
    for(int i = 0; i<N; i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
    }
}

int bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now==99)
            return true;
        for(int i = 0; i<a[now].size(); i++){
            int next = a[now][i];
            if(visited[next] == 0){
                visited[next] = 1;
                q.push(next);
            }
        }
    }
    return false;
}

int main(void){
    while(T--){
        init();
        cout<<"#"<<test_case<<" "<<bfs(0)<<"\n";
    }
    return 0;
}