#include <iostream>
using namespace std;

int n, m;
int flag, a, b;
int arr[1000000];

int findParent(int a){
    if(arr[a] != a)
        arr[a] = findParent(arr[a]);
    return arr[a];
}

void check(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if(a == b)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}

void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if(a>b)
        arr[a] = b;
    else
        arr[b] = a;
}

void solve(){
    int flag, a, b;
    cin>>flag>>a>>b;
    if(flag == 0)
        unionParent(a, b);
    else
        check(a, b);
}


int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>m;
    for(int i = 0; i<=n; i++){
        arr[i] = i;
    }
    for(int i = 0; i<m; i++){
        solve();
    }
    return 0;
}