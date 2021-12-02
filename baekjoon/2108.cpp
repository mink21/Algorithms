#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int num[8001] = {0};
vector<int> arr;

int getMode(void){
    bool secondFlag = false;
    int mostFrequent = 0;
    int ans;
    for(int i = 0; i<8001; i++){
        if(num[i] == 0)
            continue;
        if(num[i] == mostFrequent){
            if(secondFlag){
                ans = i-4000;
                secondFlag = false;
            }
        }
        if(num[i]>mostFrequent){
            mostFrequent = num[i];
            ans = i-4000;
            secondFlag = true;
        }
    }
    return ans;
}

void solve(void){
    cin>>n;
    
    int temp;
    int sum = 0;
    for(int i = 0; i<n; i++){
        cin>>temp;
        num[temp+4000]++;
        arr.push_back(temp);
        sum+=temp;
    }
    
    sort(arr.begin(), arr.end());
    int mean = round((float)sum/n);
    int median = arr[arr.size()/2];
    int mode = getMode();
    int range = arr.back()-arr.front();
    cout<<mean<<"\n"<<median<<"\n"<<mode<<"\n"<<range<<"\n";
}

int main(void){
    solve();
    return 0;
}