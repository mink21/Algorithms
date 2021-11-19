#include <iostream>
#include <math.h>
#define MAX 10000

using namespace std;

bool isPrime[MAX+1];

void sieve_of_eratosthenes(int max){
    isPrime[1] = false;
    for(int i = 2; i<max+1; i++){
        isPrime[i] = true;
    }
    int sqrtn = sqrt(max);
    for(int i = 2; i<sqrtn+1; i++){
        if(!isPrime[i]) continue;
        for(int j = i+i; j<max+1; j+=i){
            isPrime[j] = false;
        }
    }
}

void solve(void){
    int m, n;
    cin>>m>>n;

    int min = 0;
    int sum = 0;
    for(int i = m; i<n+1; i++){
        if(isPrime[i]){
            if(min == 0){
                min = i;
            }
            sum += i;
        }
    }

    if(min == 0){
        cout<<"-1"<<endl;
    }else{
        cout<<sum<<" "<<min<<endl;
    }
}

int main(void){
    sieve_of_eratosthenes(MAX+1);
    solve();
    return 0;
}