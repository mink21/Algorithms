#include <iostream>

using namespace std;

void solve(void){
    int numCnt;
    cin>>numCnt;

    //initialize
    int countSort[10001] = {0};

    //count
    int temp;
    for(int i = 0; i<numCnt; i++){
        cin>>temp;
        countSort[temp]++;
    }

    //print
    for(int i = 1; i<10001; i++){
        for(int i = 0; i<countSort[i]; i++){
            cout<<i<<endl;
        }
    }
}

int main(void){
    solve();
    return 0;
}