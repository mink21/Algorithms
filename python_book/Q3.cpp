#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int cnt = 0;
    string s;
    cin >> s;

    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] != s[i + 1])
            cnt++;
    }

    if (cnt % 2 == 0)
        cout << cnt / 2 << "\n";
    else
        cout << cnt / 2 - 1 << "\n";
    return 0;
}