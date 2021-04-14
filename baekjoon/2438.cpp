#include <iostream>
using namespace std;

void solve(){
    int N;
    cin>>N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<=i; j++){
            cout<<"*";
        }
        cout<<"\n";
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();
    
    return 0;
}