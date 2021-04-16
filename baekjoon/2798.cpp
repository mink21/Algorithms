#include <iostream>
using namespace std;

int main(void){
    int N, M, max = 0, sum;
    cin>>N>>M;
    int card[N];
    for(int i = 0; i<N; i++){
        cin>>card[i];
    }
    for(int i = 0; i<N-2; i++){
        for(int j = i+1; j<N-1; j++){
            for(int k = j+1; k<N; k++){
                sum = card[i]+card[j]+card[k];
                if(sum == M){
                    max = M;
                    break;
                }else if((sum>max) && (sum<M)){
                    max = sum;
                }
            }
        }
    }
    cout<<max<<endl;
    return 0;
}