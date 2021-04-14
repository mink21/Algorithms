#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int min_coins(int *array, int N, int K){
    int remainder = K;
    int numCoin = 0;
    int place = N-1;
    while(remainder != 0){
        while(array[place]<=remainder){
            //cout<<remainder<<" "<<numCoin<<endl;
            remainder -= array[place];
            numCoin++;
        }
        place--;
    }
    return numCoin;
}

void solve(){
    //read input
    int N, K, result;
    cin>>N>>K;
    int coins[N];
    for(int i = 0; i<N; i++){
        cin>>coins[i];
    }
    //calculate
    result = min_coins(coins, N, K);

    //print output
    cout<<result<<endl;
}

int main(void){
    solve();
    return 0;
}