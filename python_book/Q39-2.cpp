#include <iostream>
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n;
int arr[100][100];
int dp[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void printArr(){
    for(int i = 0; i<n; i++){
    	for(int j = 0; j<n; j++){
        	cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int solve(void){
	cin>>n;
    for(int i = 0; i<n; i++){
    	for(int j = 0; j<n; j++){
        	char temp;
            cin>>temp;
            arr[i][j] = int(temp)-48;
        }
    }
    for(int i = 0; i<n; i++){
    	fill(dp[i], dp[i] + 125, INF);
    }

    int x = 0, y = 0;
    priority_queue<pair<int, pair<int, int> > > pq;
    pq.push({-arr[x][y], {0,0}});
    dp[x][y] = arr[x][y];

    while(!pq.empty()){
        int time = -pq.top().first;
        x = pq.top().second.first;
        y = pq.top().second.second;
        pq.pop();
        if(dp[x][y]<time) 
            continue;
        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>= n)
                continue;
            int cost = time + arr[nx][ny];
            if(cost<dp[nx][ny]){
                dp[nx][ny] = cost;
                pq.push({-cost, {nx, ny}});
            }
        }
    }
    return dp[n-1][n-1];
}

int main(int argc, char** argv)
{
    int test_case, ans;
    cin>>test_case;
    for(int i = 0; i<test_case; i++){
    	ans = solve();
        cout<<"#"<<i+1<<" "<<ans<<"\n";
    }
	return 0;
}