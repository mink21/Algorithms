#include <iostream>
using namespace std;

int solve()
{
    int n, k;
    cin >> n >> k;
    char str[n];
    for (int i = 0; i < n; i++)
        cin >> str[i];

    int result = 0;
    for (int i = 0; i < n / 2; i++)
    {
        result *= str[i] - 96;
    }
    return result;
}

int main(void)
{
    int test_cases, result;
    cin >> test_cases;
    for (int i = 0; i < test_cases; i++)
    {
        result = solve();
        cout << "Case #" << i + 1 << " " << result << "\n";
    }
    return 0;
}