#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Time{
    int begin;
    int end;
};

bool comp(Time a, Time b){
    if(a.end == b.end)
        return a.begin<b.begin;
    else
        return a.end<b.end;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, count, num;
    cin>>N;
    vector<Time> t(N);
    for(int i = 0; i<N; i++){
        cin>>t[i].begin>>t[i].end;
    }

    sort(t.begin(), t.end(), comp);

    count = 0;
    num = 0;
    for(int i = 0; i<N; i++){
        if(num<=t[i].begin){
            num = t[i].end;
            count++;
        }
    }

    cout<<count<<"\n";
    return 0;
}