#include <iostream>
#include <math.h>

using namespace std;

void solve(void)
{
    long long ans, x, y;
    cin >> x >> y;

    ans = (int)sqrt(y - x);
    if (y - x == ans * ans)
    {
        cout << 2 * ans - 1 << endl;
    }
    else if (ans * ans < (y - x) && (y - x) <= ans * ans + ans)
    {
        cout << 2 * ans << endl;
    }
    else if (ans * ans + ans < (y - x) && (y - x) < (a + 1) * (a + 1))
    {
        cout << 2 * ans + 1 << endl;
    }
}

int main(void)
{
    int testcase;
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        solve();
    }
    return 0;
}