#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string n1, n2, ans;
    cin >> n1 >> n2;

    int carry = 0;
    int n1size = n1.size();
    int n2size = n2.size();

    while (n1size > 0 || n2size > 0)
    {
        int nn1 = 0;
        if (n1size > 0)
        {
            nn1 = n1[--n1size] - '0';
        }

        int nn2 = 0;
        if (n2size > 0)
        {
            nn2 = n2[--n2size] - '0';
        }

        int cur = nn1 + nn2 + carry;
        carry = cur / 10;
        cur %= 10;
        char curChar = cur + '0';
        ans += curChar;
    }

    if (carry > 0)
    {
        ans += carry + '0';
    }

    for (int i = ans.size() - 1; i > -1; i--)
    {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}