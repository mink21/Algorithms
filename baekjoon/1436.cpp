#include <iostream>

using namespace std;

void solve(void){
    int n;
    cin>>n;

    int num = 666;
    int cnt = 0;
    while(true){
        int temp = num;
        while(temp>0){
            if(temp%1000 ==666){
                cnt++;
                break;
            }
            temp/=10;
        }
        if(cnt == n){
            cout<<num<<endl;
            break;
        }
        num++;
    }
}

int main(void){
    solve();
    return 0;
}