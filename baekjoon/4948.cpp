#include <iostream>
#include <math.h>
#define MAX 123456*2

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

void solve(int n){
    int cnt = 0;
    for(int i = n+1; i<2*n+1; i++){
        if(isPrime[i]) cnt++;
    }
    cout<<cnt<<endl;
}

int main(void){
    int input;
    cin>>input;

    sieveOfEratosthenes();
    while(input != 0){
        solve(input);
        cin>>input;
    }
    return 0;
}