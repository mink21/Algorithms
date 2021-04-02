#include <iostream>
using namespace std;

int zero[41], one[41];

void fibonacci()
{
    zero[0] = 1;
    zero[1] = 0;
    one[0] = 0;
    one[1] = 1;

    for (int i = 2; i < 41; i++)
    {
        zero[i] = zero[i - 1] + zero[i - 2];
        one[i] = one[i - 1] + one[i - 2];
    }
}

int main(void)
{
    int T;
    cin >> T;
    fibonacci();
    for (int test_case = 0; test_case < T; test_case++)
    {
        int N;
        cin >> N;
        cout << zero[N] << " " << one[N] << endl;
    }
}