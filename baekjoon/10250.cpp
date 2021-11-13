#include <iostream>
using namespace std;

int solve(){
    int h, w, n;
    cin>>h>>w>>n;
    if(n%h){
        return (n%h)*100 + n/h + 1;
    }else{
        return (h)*100 + n/h; 
    }
}

int main(void){
    int testcase, ans;
    cin>>testcase;
    for(int i = 0; i<testcase; i++){
        ans = solve();
        cout<<ans<<"\n";
    }
    return 0;
}