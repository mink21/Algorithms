#include <iostream>
using namespace std;

int main(void){
    int n;
    int arr[500][500];
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j<=i; j++){
            cin>>arr[i][j];
        }
    }

    int left, right;
    for(int i = 1; i<n; i++){
        for(int j = 0 ; j <=i; j++){
            if(j == 0)
                left = 0;
            else
                left = arr[i-1][j-1];
            if(j == i)
                right = 0;
            else
                right = arr[i-1][j];
            if(left>right)
                arr[i][j] += left;
            else
                arr[i][j] += right;
        }
    }

    int max = 0;
    for(int i = 0; i<n; i++){
        if(max<arr[n-1][i])
            max = arr[n-1][i];
    }
    cout<<max<<"\n";
    return 0;
}