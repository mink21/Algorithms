#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, k = 1, i = 1;
    cin >> x;

    for (i = 1; i < x; i++)
    {
        x -= i;
        k *= -1;
    }

    if (k == -1)
        cout << x << "/" << i + 1 - x << endl;
    else
        cout << i + 1 - x << "/" << x << endl;

    return 0;
}