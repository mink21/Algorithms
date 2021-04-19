#include <iostream>
#include <string>
using namespace std;

int N;
int ans[200000];

void solve()
{
    string str;
    cin >> N >> str;
    for (int i = 0; i < N; i++)
    {
        ans[i] = 1;
        if (str[i] > str[i - 1])
            ans[i] = ans[i - 1] + 1;
    }
}

int main(void)
{
    int test_case;
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
        for (int i = 0; i < N; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}