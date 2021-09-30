#include <iostream>
#include <queue>

using namespace std;

int n;
queue<int> q;

void solve(void){
    q.pop();
    int temp = q.front();
    q.pop();
    q.push(temp);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;
    for(int i = 1; i<=n; i++){
        q.push(i);
    }
    
    while(q.size() != 1){
        solve();
    }

    int ans;
    ans = q.front();
    cout<<ans<<"\n";
    
    return 0;
}