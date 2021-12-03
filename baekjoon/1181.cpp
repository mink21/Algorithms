#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    if(a.length() == b.length())
        return a<b;
    return a.length()<b.length();
}

void solve(void){
    int n;
    cin>>n;
    
    vector<string> v;
    for(int i = 0; i<n; i++){
        string str;
        cin>>str;
        if(find(v.begin(), v.end(), str) == v.end())
            v.push_back(str);
    }
    
    sort(v.begin(), v.end(), compare);
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<'\n';
    }
}

int main(void){
    solve();
    return 0;
}