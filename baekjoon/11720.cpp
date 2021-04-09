#include <iostream>
using namespace std;

int main(void)
{
    int N, sum = 0;
    cin >> N;
    char num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        sum += num - '0';
    }
    cout << sum << endl;
    return 0;
}