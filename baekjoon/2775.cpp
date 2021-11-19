#include <iostream>

using namespace std;

int house[15][14];

// calculate the number of people
void calculate(void)
{
    // floor 0
    for (int i = 0; i < 14; i++)
    {
        house[0][i] = i + 1;
    }

    // floor 1 to 14
    for (int i = 1; i < 15; i++)
    {
        house[i][0] = 1;
        for (int j = 1; j < 14; j++)
        {
            house[i][j] = house[i][j - 1] + house[i - 1][j];
        }
    }
}

void solve(void)
{
    int k, n;
    cin >> k >> n;
    cout << house[k][n - 1] << endl;
}

int main(void)
{
    int testcase;
    cin >> testcase;
    calculate();
    for (int i = 0; i < testcase; i++)
    {
        solve();
    }
    return 0;
}