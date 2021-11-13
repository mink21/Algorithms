#include <iostream>
#include <string>

using namespace std;

void solve(void)
{
    string s;
    getline(cin, s);

    int cnt = 0;
    bool flag = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            flag = true;
        }
        else if (flag)
        {
            flag = false;
            cnt++;
        }
    }

    cout << cnt << endl;
}

int main(void)
{
    solve();
    return 0;
}