#include <iostream>
#include <utility>

using namespace std;

void solve(void){
    int n, rank;
    pair<int,int> arr[50];
    
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>arr[i].first>>arr[i].second;
    }

    rank = 1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(arr[i].first < arr[j].first && arr[i].second < arr[j].second){
                rank++;
            }
        }
        cout<<rank<<" ";
        rank = 1;
    }
}

int main(void){
    solve();
    return 0;
}