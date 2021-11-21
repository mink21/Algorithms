#include <iostream>
#include <math.h>
#include <vector>

#define MAX 10000

using namespace std;

bool isPrime[MAX+1];
vector <int> primeNum;

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

void getPrimeNum(){
    for(int i = 2; i<10000; i++){
        if(isPrime[i]){
            primeNum.push_back(i);
        }
    }
}

void solve(void){
    int n;
    cin>>n;
    sieveOfEratosthenes();
    getPrimeNum();

    int idx = 0;
    while(n!=1){
        int prime = primeNum[idx];
        while(n%prime == 0){
            cout<<prime<<endl;
            n /= prime;
        }
        idx++;
    }
}

int main(void){
    solve();
    return 0;
}