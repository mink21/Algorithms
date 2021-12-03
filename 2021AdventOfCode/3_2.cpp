#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string oxygenGenerator(vector<string> v){
    int pos = 0;
    while(v.size()>1){
        char mid = v[v.size()/2][pos];
        for(int i = v.size()-1; i>-1; i--){
            if(v[i][pos] != mid){
                v.erase(v.begin() + i);
            }
        }
        pos++;
    }
    return v[0];
}

string co2Scrubber(vector<string> v){
    int pos = 0;
    while(v.size()>1){
        char mid = v[v.size()/2][pos];
        for(int i = v.size()-1; i>-1; i--){
            if(v[i][pos] == mid){
                v.erase(v.begin() + i);
            }
        }
        pos++;
    }
    return v[0];
}

int binaryToDecimal(string s){
    int size = s.size();
    int ans = 0;
    for(int i = 0; i<size; i++){
        ans += (s[i] - '0') * pow(2, size-1-i);
    }
    return ans;
}

void solve(void){
    vector<string> v;
    string str;
    while(true){
        getline(cin, str);
        if(str == "")
            break;
        
        v.push_back(str);
    }

    sort(v.begin(), v.end());

    string ox = oxygenGenerator(v);
    string co2 = co2Scrubber(v);
    cout<<ox<<" "<<co2<<endl;

    int oxInt = binaryToDecimal(ox);
    int co2Int = binaryToDecimal(co2);
    cout<<oxInt<<" "<<co2Int<<endl;
    
    cout<<oxInt*co2Int<<endl;
}

int main(void){
    solve();
    return 0;
}