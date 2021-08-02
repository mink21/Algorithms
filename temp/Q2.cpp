#include <iostream>
using namespace std;

int n, t, right, left;
char arrB[50001];
char arrA[50001];
bool set[50001];

void calculateA()
{
    for (int i = 0; i < n; i++)
    {
    }
}

void readInput()
{
    for (int i = 0; i < n; i++)
    {
        cin >> arrB[i];
        if (i < t)
        {
            arrA[i + t] = arrB[i];
            set[i + t] = 1;
        }
        else if (i > n - t - 1)
        {
            arrA[i - t] = arrB[i];
            set[i - t] = 1;
        }
        else if (arrB[i] == 0)
        {
            arrA[i + t] = 0;
            set[i + t] = 1;
            arrA[i - t] = 0;
            set[i - t] = 0;
        }
    }
}

void solve()
{
    ans = 0;
    set[] = {};
    cin >> n >> t;
    readInput();
    calculateA();
}

int main(void)
{
    int test_case;
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        solve();
        cout << "Case #" << i + 1 << "\n";
        for (int i = 0; i < n; i++)
            cout << arrA[i];
        cout << "\n";
    }
    return 0;
}