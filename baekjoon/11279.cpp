#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> q;

void solve(void){
    int temp;
    cin>>temp;
    if(temp == 0){
        if(q.empty()){
            cout<<"0\n";
        }else{
            cout<<q.top()<<"\n";
            q.pop();
        }
    }else{
        q.push(temp);
    }
}

int main(void){
    int test_case;
    cin>>test_case;
    for(int i = 0; i<test_case; i++){
        solve();
    }
    return 0;
}