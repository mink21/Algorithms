#include <iostream>

using namespace std;

void solve(void){
    int one, two, three, four;
    cin>>one>>two>>three>>four;

    int temp1, temp2;
    cin>>temp1>>temp2;
    //x
    if(temp1 == one){
        cout<<three<<" ";
    }else if(temp1 == three){
        cout<<one<<" ";
    }else{
        cout<<temp1<<" ";
    }
    //y
    if(temp2 == two){
        cout<<four<<endl;
    }else if(temp2 = four){
        cout<<two<<endl;
    }else{
        cout<<temp2<<endl;
    }
}

int main(void){
    solve();
    return 0;
}