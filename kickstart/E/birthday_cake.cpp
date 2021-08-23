#include <iostream>
using namespace std;

int r, c, k;
int r1, c1, r2, c2;

int solve(void){
    cin>>r>>c>>k;
    cin>>r1>>c1>>r2>>c2;

}

int main(void){
    int test_case, answer;
    cin>>test_case;
    for(int i = 0; i<test_case; i++){
        answer = solve();
        cout<<"Case #"<<i+1<<": "<<answer<<"\n";
    }
    return 0;
}