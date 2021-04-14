#include <iostream>
using namespace std;

void solve(){
    int array[9];
    int max = 0, position;
    for(int i = 0; i<9; i++){
        cin>>array[i];
        if(array[i]>max) {
            max = array[i];
            position = i+1;
        }
    }
    cout<<max<<"\n"<<position<<"\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}