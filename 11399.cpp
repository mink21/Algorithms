#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int N, input, sum = 0, add = 0;
    cin>>N;
    int p[N];
    for(int i = 0; i<N; i++)
        cin>>p[i];

    sort(p, p+N);

    for(int i = 0; i<N; i++){
        sum += (add + p[i]);
        add += p[i];
    }

    cout<<sum<<"\n";
    return 0;
}