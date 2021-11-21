#include <iostream>

using namespace std;

void solve(void){
    int n;
    cin>>n;
    for(int i = 2; i*i < n+1; i++){
        while(n%i == 0){
            cout<<i<<endl;
            n/=i;
        }
    }
    if(n>1){
        cout<<n<<endl;
    }
}

int main(void){
    solve();
    return 0;
}