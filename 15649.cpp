#include <iostream>
using namespace std;

int check(int arr[], int index, int i){
    for(int j = 0; j<index; j++){
        if(arr[j] == i){
            return 0;
        }
    }
    return 1;
}

void solve(int arr[], int N, int M, int index){
    if(index == M){
        for(int i = 0; i<M; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i = 1; i<=N; i++){
        arr[index] = i;
        if(check(arr, index, i) == 1){
            solve(arr, N, M, index+1);
        }
     }
}

int main(void){
    //time
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //input
    int N, M;
    cin>>N>> M;
    
    //calculate
    int arr[M];
    solve(arr, N, M, 0);
    
    return 0;
}