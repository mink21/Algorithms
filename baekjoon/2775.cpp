#include <iostream>
using namespace std;

int building[14][14];

void calculate(){
    for(int i = 0; i<14; i++){
        for(int j= 0; j<14; j++){
            if(i == 0)
                building[i][j] = j+1;
            else{
                for(int k = 0; k<=j;k++){
                    building[i][j] += building[i-1][k];
                }
            }      
        }
    }

}

void print(){
    for(int i = 0; i<14; i++){
        for(int j = 0; j<14; j++){
            cout<<building[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void solve(){
    int n, k;
    cin>>n>>k;
    cout<<building[n][k-1]<<"\n";
}

int main(void){
    int testcase, n, k;
    cin>>testcase;
    calculate();
    print();
    for(int i = 0; i<testcase; i++){
        solve();
    }
    return 0;
}