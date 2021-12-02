#include <iostream>

using namespace std;

void solve(void){
    double r;
    cin>>r;

    const double pi = 3.14159265358979323846;
    double euclid = pi * r * r;
    double taxi = 2*r*r;

    cout<<fixed;
    cout.precision(6);
    cout<<euclid<<endl<<taxi<<endl;
}

int main(void){
    solve();
    return 0;
}


//euclid distance = root((a1-b1)^2 + (a2-b2)^2)
//taxi distance = |x1-x2| + |y1-y2|