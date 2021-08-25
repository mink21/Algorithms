#include <iostream>
using namespace std;

int main(void)
{
    int s, ans = 1;
    cin >> s;
    while (s > 0)
    {
        if ((s % 10) == 0)
            continue;
        else
            ans *= (s % 10);
        s /= 10;
    }
    cout << ans << "\n";
    return 0;
}