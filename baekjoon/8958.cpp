#include <iostream>
#include <string.h>
using namespace std;

void solve()
{
    int score = 0, adj = 0;
    char row[80];
    cin >> row;
    for (int i = 0; i < strlen(row); i++)
    {
        if (row[i] == 'O')
        {
            adj++;
            score += adj;
        }
        else
        {
            adj = 0;
        }
    }
    cout << score << "\n";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        solve();
    }
    return 0;
}