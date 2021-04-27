#include <iostream>
using namespace std;

int main(void){
    int N, M, K;
    int temp, max, max2, ans;
    cin>>N>>M>>K;
    max = 0;
    max2 = 0;
    for(int i = 0; i<N; i++){
        cin>>temp;
        if(temp>max){
            max2 = max;
            max = temp;
        }else if(temp==max)
            max2 = temp;
        else if(temp>max2)
            max2 = temp;
    }
    //also possible to sort and find the biggest and second biggest number

    ans = (M/(K+1))*(max*K + max2) + (M%(K+1))*max;
    //also possible to set count as num of times biggest number gets added and use that
    cout<<ans<<"\n";
    return 0; 
}