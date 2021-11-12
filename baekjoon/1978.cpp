#include <iostream>
#include <cmath>

#define MAX 1000+1
using namespace std;

int n;
bool isPrime[MAX];

void checkIsPrime(){
    for(int i = 2; i<MAX; i++){
        isPrime[i] = 1;
    }
    int sqrtn = sqrt(MAX);
    for(int i = 2; i<=sqrtn; i++){
        if(!isPrime[i]) continue;
        for(int j = i+i; j<=n; j += i){
            isPrime[j] = 0;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    checkIsPrime();

    int temp, ans = 0;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>temp;
        if(isPrime[temp]) ans++;
    }

    cout<<ans<<"\n";
    return 0;
}