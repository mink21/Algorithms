#include <iostream>
#include <algorithm>

using namespace std;

int n;
int num[11];
int operators[4];
int maxValue = -1000000001;
int minValue = 1000000001;

void calculate(int sum, int idx, int a, int s, int m, int d){
    if(idx == n){
        if(sum>maxValue)
            maxValue = sum;
        if(sum<minValue)
            minValue = sum;
        return;
    }
    if(a>0)
        calculate(sum+num[idx], idx+1, a-1, s, m, d);
    if(s>0)
        calculate(sum-num[idx], idx+1, a, s-1, m, d);
    if(m>0)
        calculate(sum*num[idx], idx+1, a, s, m-1, d);
    if(d>0)
        calculate(sum/num[idx], idx+1, a, s, m, d-1);
}

void solve(void){
    cin>>n;
    for(int i = 0; i<n; i++)
        cin>>num[i];
    for(int i = 0; i<4; i++)
        cin>>operators[i];
    calculate(num[0], 1, operators[0], operators[1], operators[2], operators[3]);
    cout<<maxValue<<"\n"<<minValue<<"\n";
}

int main(void){
    solve();
    return 0;
}