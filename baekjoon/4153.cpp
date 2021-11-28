#include <iostream>

using namespace std;

bool checkRightTriangle(int x, int y, int z){
    bool ans = false;
    if(x>=y && x>=z){
        ans = (x*x == y*y + z*z)? true : false;
    }
    if(y>=x && y>=z){
        ans = (y*y == x*x + z*z)? true: false;
    }
    if(z>=y && z>=x){
        ans = (z*z == y*y + x*x)? true: false;
    }
    return ans;
}

int main(void){
    int x, y, z;
    while(true){
        cin>>x>>y>>z;
        if(x==0){
            break;
        }
        if(checkRightTriangle(x, y, z)){
            cout<<"right\n";
        }else{
            cout<<"wrong\n";
        }
    }
    return 0;
}