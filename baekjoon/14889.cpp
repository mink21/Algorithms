//시간초과

#include <iostream>
#include <math.h>

using namespace std;

int n, ans = 1000000000;
int ability[21][21];
bool team[21];

void dfs(int people, int next){
    if(people == n/2){
        int start = 0;
        int link = 0;
        for(int i = 1; i<n+1; i++){
            for(int j = i+1; j<n+1; j++){
                if(team[i] && team[j]){
                    start += ability[i][j];
                    start += ability[j][i];
                }else if(!team[i] && !team[j]){
                    link += ability[i][j];
                    link += ability[j][i];
                }
            }
        }
        ans = min(ans, abs(start-link));
    }
    for(int i = 1; i<n+1; i++){
        if(!team[i] && i>next){
            team[i] = true;
            dfs(people+1, next);
            team[i] = false;
        }
    }
}

int main(void){
    cin>>n;
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<n+1; j++){
            cin>>ability[i][j];
        }
    }
    dfs(0, 1);
    cout<<ans<<"\n";
}