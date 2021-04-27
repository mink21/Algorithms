#include <iostream>
using namespace std;

int main(void){
    int N, answer, stack, priceMin;
    cin>>N;
    int dist[N-1];
    int price[N];
    for(int i = 0; i<N-1; i++)
        cin>>dist[i];
    for(int i = 0; i<N; i++)
        cin>>price[N];
    
    answer = dist[0] * price[0];
    stack = 0;
    priceMin = 0;
    for(int i = 1; i<N-1; i++){
        if(price[i]>price[i-1])
            stack += dist[i-1];
        else
            answer ;
    }
}