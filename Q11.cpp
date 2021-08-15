//0 is empty
//1 is apple
//2 is snake body

#include <iostream>
#include <queue>
using namespace std;

int n, k, l, ans = 0;
int box[101][101] = {};

bool checkDeath(int posx, int posy){
    //wall
    if(posx<1 || posx >n || posy<1 || posy>n)
        return true;
    //self
    if(box[posx][posy] == 2)
        return true;
    //neither is true and the game goes on
    return false;
}

int main(void){
    cin>>n>>k;
    int temp1, temp2;
    for(int i = 0; i<k; i++){
        cin>>temp1>>temp2;
        box[temp1][temp2] = 1;
    }

    cin>>l;
    int posx = 1, posy = 1;
    int head = 0, length = 1;
    int dx[4] = {1, 0, -1, -};
    int dy[4] = {0, -1, 0, 1};
    char temp3;
    
    box[posx][posy] = 2;
    for(int i = 0; i<l; i++){
        cin>>temp1>>temp3;
        for(int j = 0; j<temp1; j++){
            posx += dx[head];
            posy += dy[head];
            box[posx][posy] = 2;
            ans++;
            if(checkDeath)
                break;
            if(box[posx][posy] == 1){
                continue;
            }else{
                //remove tail use queue
            }
        }
        if(temp3 == 'L'){
            head--;
            if(head<0)
                head = 3;
        }else{
            head++;
            if(head>3)
                head = 0;
        }
    }

    cout<<ans<<"\n";
    return 0;
}