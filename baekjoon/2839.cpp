#include <iostream>

using namespace std;

int solve(void)
{
    int n;
    cin >> n;

    int five = n / 5;
    int remainder = n % 5;
    while (five > -1)
    {
        if ((remainder % 3) == 0)
        {
            return five + remainder / 3;
        }
        five--;
        remainder += 5;
    }

    return -1;
}

int main(void)
{
    int ans = solve();
    cout << ans << endl;
    return 0;
}