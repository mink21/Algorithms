#include <iostream>
#include <math.h>
#define MAX 10000

using namespace std;

bool isPrime[MAX+1];

void sieveOfEratosthenes(void){
    for(int i = 2; i<MAX+1; i++){
        isPrime[i] = true;
    }
    int sqrtn = sqrt(MAX);
    for(int i = 2; i<sqrtn+1; i++){
        if(!isPrime[i]) continue;
        for(int j = i+i; j<MAX+1; j+=i){
            isPrime[j] = false;
        }
    }
}

void solve(void){
    int n;
    cin>>n;

    for(int i = n/2; i>1; i--){
        if(isPrime[i] && isPrime[n-i]){
            cout<<i<<" "<<n-i<<endl; 
            break;
        }
    }
}

int main(void){
    int testcase;
    cin>>testcase;
    sieveOfEratosthenes();
    
    for(int i = 0; i<testcase; i++){
        solve();
    }
    return 0;
}