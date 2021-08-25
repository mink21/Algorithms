#include <iostream>
using namespace std;

int n, m;
int gold[20][20];
int dp[20][20];

void dynamicGold(int a, int b){
    int left[3];
    int max = 0;
    
    //left up
    if(a == 0)
        left[0] = 0;
    else
        left[0] = dp[a-1][b-1];
    
    //left
    left[1] = dp[a][b-1];
    
    //left down
    if(a == (n-1))
        left[2] = 0;
    else
        left[2] = dp[a+1][b-1];

    //find max
    for(int i = 0; i<3; i++){
        if(max<left[i]){
            max = left[i];
        }
    }
    dp[a][b] = gold[a][b] + max;
}

void printDP(){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
     cout<<"\n";
}

void solve(void){
    cin>>n>>m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>gold[i][j];
            dp[i][j] = gold[i][j];
        }
    }

    for(int i = 1; i<m; i++){
        for(int j = 0; j<n; j++){
            dynamicGold(j, i);
            //printDP();
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