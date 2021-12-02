#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second)
        return a.first<b.first;
    return a.second<b.second;
}

void solve(void){
    int n;
    cin>>n;

    int x, y;
    vector<pair<int, int>> vec;
    for(int i = 0; i<n; i++){
        cin>>x>>y;
        vec.push_back(make_pair(x, y));
    }

    sort(vec.begin(), vec.end(), compare);

    for(int i = 0; i<n; i++){
        cout<<vec[i].first<<" "<<vec[i].second<<"\n";
    }
}

int main(void){
    solve();
    return 0;
}