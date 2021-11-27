#include <iostream>

using namespace std;

int n, count = 0;
int col[15];

bool check(int level){
    for(int i = 0; i<level; i++){
        if(col[i] == col[level] || abs(col[level] - col[i]) == level - i)
            return false;
    }
    return true;
}

void nqueen(int x){
    if(x == n){
        count++;
    }else{
        for(int i = 0; i<n; i++){
            col[x] = i;
            if(check(x)){
                nqueen(x+1);
            }
        }
    }
}

int main(void){
    cin>>n;
    nqueen(0);
    cout<<count<<endl;
    return 0;
}