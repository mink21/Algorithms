#include <iostream>
using namespace std;

int fib[40];
int zero = 0, one = 0;

int fibonacci(int n){
    if(n == 0){
        fib[0] = 0;
        return 0;
    } else if(n == 1){
        fib[1] = 1;
        return 1;
    } else{
        return fibonacci(n-1) + fibonacci(n-2);
    }

}

int main(void)
{
    int T;
    cin>>T;
    for(int test_case = 0; test_case<T; test_case++)
    {
        int N, count;
        cin>>N;
        count = fibonacci(N);
        cout<<zero<<" "<<one<<endl;

    }

}