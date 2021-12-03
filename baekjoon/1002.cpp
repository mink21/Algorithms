#include <iostream>
#include <cmath>

using namespace std;

void solve(void){
    int x1, y1, r1, x2, y2, r2;
    cin>>x1>>y1>>r1>>x2>>y2>>r2;

    int dist = pow((x2-x1), 2) + pow((y2-y1), 2);
    int cond1 = pow((r1 - r2), 2);
    int cond2 = pow((r1 + r2), 2);

    if(dist == 0){
        if(cond1 == 0)
            cout<<"-1"<<endl;
        else
            cout<<"0"<<endl;
        return;
    }

    if(cond1<dist && dist<cond2)
        cout<<"2"<<endl;
    else if(dist == cond1 || dist == cond2)
        cout<<"1"<<endl;
    else
        cout<<"0"<<endl;
}

int main(void){
    int testcase;
    cin>>testcase;
    for(int i = 0; i<testcase; i++){
        solve();
    }
    return 0;
}