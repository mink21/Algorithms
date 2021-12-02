#include <iostream>

using namespace std;

void solve(void){
    int x, y, w, h;
    cin>>x>>y>>w>>h;

    int min = 1000;
    if(x<min)
        min = x;
    if(y<min)
        min = y;
    if((w-x)<min)
        min = w-x;
    if((h-y)<min)
        min = h-y;
    
    cout<<min<<endl;
}

int main(void){
    solve();
    return 0;
}