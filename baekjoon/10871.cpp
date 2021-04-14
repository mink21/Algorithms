#include <iostream>
using namespace std;

void solve(){
    int N, X;
    cin>>N>>X;
    int array[N];
    for(int i = 0; i<N; i++){
        cin>>array[i];
        if(array[i]<X){
            cout<<array[i]<<" ";
        }
    }
    cout<<"\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();
    return 0;
}