#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(pair<int,string> a, pair<int,string> b){
    return a.first<b.first;
}

void solve(void){
    int n;
    cin>>n;
    
    vector<pair<int,string>> v;
    for(int i = 0; i<n; i++){
        int age;
        string name;
        cin>>age>>name;
        v.push_back(make_pair(age, name));
    }
    
    stable_sort(v.begin(), v.end(), compare);
    
    for(int i = 0; i<n; i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}