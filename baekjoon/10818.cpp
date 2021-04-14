#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, temp, min = 1000000, max = -1000000;
    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>temp;
        if(temp>max) max = temp;
        if(temp<min) min = temp;       
    }
    
    cout<<min<<" "<<max<<"\n";
    return 0;
}