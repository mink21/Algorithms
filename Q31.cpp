#include <iostream>
using namespace std;

int n, m;
int left_up, left_down, left;
int gold[20][20];
int dp[20][20];

void dynamicGold(int a, int b){
    if(b == 0)
        left_up = 0;
    else
        left_up = dp[a-1][b-1];
    
    if(b == n-1)
        left_down = 0;
    else
        left_down = dp[a-1][b+1];

    left = dp[a-1][b];

}

void solve(void){
    cin>>n>>m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>gold[i][j];
            dp[i][j] = gold[i][j];
        }
    }

    for(int i = 1; i<n; i++){
        for(int j = 0; j<m; j++){
            dynamicGold(i, j);
        }
    }

    int max = 0;
    for(int i = 0; i<n; i++){
        if(max < dp[i][m-1])
            max = dp[i][m-1];
    }

    cout<<max<<"\n";
}

int main(void){
    int test_case;
    cin>>test_case;
    for(int i = 0; i<test_case; i++)
        solve();
    return 0;
}