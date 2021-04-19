#include <iostream>
#include <string>
using namespace std;

int solve()
{
    int alpha[26] = {};
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        int num = str[i] - 97;

        /*cout << num << "  ";
        for (int j = 0; j < 26; j++)
        {
            cout << alpha[j] << " ";
        }
        cout << endl;*/

        if (alpha[num] == 0)
        {
            alpha[num]++;
        }
        else if (alpha[num] == 1 && str[num - 1] != str[num])
        {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    int N, ans = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        ans += solve();
    }
    cout << ans << endl;
    return 0;
}