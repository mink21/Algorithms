#include <iostream>

using namespace std;

int minCoin(int *coins, int n, int k){
    int numCoin = 0;
    for(int i = n-1; i>=0; i--){
        while(k>=coins[i]){
            k -= coins[i];
            numCoin++;
            cout<<k<< " " <<coins[i]<<" "<<numCoin<<"\n";
        }
    }
    return numCoin;
}

void solve(void){
    //read input;
    int n, k, result;
    int coins[10];
    cin>>n>>k;
    for(int i = 0; i<n; i++){
        cin>>coins[i];
    }
    
    //get output and print
    result= minCoin(coins, n, k);
    cout<<result<<"\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}