#include <iostream>
using namespace std;

int main(void){
    int n, m, a, b, ans, cnt;
    int arr[501][501];

    cin>>n>>m;

    //initialize
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            arr[i][j] = 1000000000;
            if(i==j)
                arr[i][j] = 0;
        }
    }

    //read input
    for(int i = 0; i<m ; i++){
        cin>>a>>b;
        arr[a][b] = 1;
    }

    //floyd marshall
    for(int k = 1; k<=n; k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                int temp = arr[i][k] + arr[k][j];
                if(temp<arr[i][j])
                    arr[i][j] = temp;
            }
        }
    }

    //calculate ans
    ans = 0;
    for(int i = 1; i<=n; i++){
        cnt = 0;
        for(int j = 1; j<=n; j++){
            if(arr[i][j] != 1000000000 || arr[j][i] != 1000000000)
                cnt++;
        }
        if(cnt == n)
            ans++;
    }
    cout<<ans<<"\n";
    return 0;
}