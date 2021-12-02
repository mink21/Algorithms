#include <iostream>

using namespace std;

void solve(void){
    int n;
    cin>>n;

    int num[10] = {0};
    while(n>0){
        num[n%10]++;
        n/=10;
    }

    for(int i = 9; i>=0; i--){
        for(int j = 0; j<num[i]; j++){
            cout<<i;
        }
    }
    cout<<endl;
}

int main(void){
    solve();
    return 0;
}