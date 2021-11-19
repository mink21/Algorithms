#include <iostream>
#include <string>

using namespace std;

bool solve(void)
{
    string s;
    cin >> s;

    bool visited[26];
    for (int i = 0; i < 26; i++)
    {
        visited[i] = false;
    }

    visited[s[0] - 97] = true;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] != s[i - 1])
        {
            if (visited[s[i] - 97])
            {
                return false;
            }
            else
            {
                visited[s[i] - 97] = true;
            }
        }
    }
    return true;
}

int main(void)
{
    int ans = 0;
    int testcase;
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        if (solve())
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}