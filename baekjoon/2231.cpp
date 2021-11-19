#include <iostream>

using namespace std;

int find_sum(int input){
    int length = 1;
    int temp = input;
    while(temp>9){
        length++;
        temp /= 10;
    }

    int sum = input;
    temp = input;
    for(int i = 0; i<length; i++){
        sum += temp%10;
        temp /= 10;
    }

    return sum;
}

void solve(void){
    int n;
    cin>>n;

    int ans = 0;
    for(int i = 1; i<1000001; i++){
        int sum = find_sum(i);
        if(sum == n){
            ans = i;
            break;
        }
    }

    cout<<ans<<endl;
}

int main(void){
    solve();
    return 0;
}