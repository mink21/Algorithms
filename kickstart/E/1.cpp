#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
    int test_case;
    string answer;
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        int max = 0;
        int alphabet[26];
        int sorted[26];
        string s, ans;
        cin >> s;

        //check if impossible
        for (int i = 0; i < 26; i++)
        {
            alphabet[i] = 0;
            sorted[i] = 0;
        }
        for (int i = 0; i < s.length(); i++)
        {
            int temp = int(s[i]) - 97;
            alphabet[temp]++;
            sorted[temp]++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (max < alphabet[i])
                max = alphabet[i];
        }
        if (max >= (s.length() + 1) / 2)
        {
            cout << "Case #" << i + 1 << ": "
                 << "IMPOSSIBLE"
                 << "\n";
            continue;
        }

        //else return shuffled
        sort(sorted, sorted + 26);
        for (int i = 0; i < 13; i++)
        {
            int temp = sorted[i];
            sorted[i] = sorted[25 - i];
            sorted[25 - i] = temp;
        }
        for (int i = 0; i < s.length(); i++)
            ans[i] = '0';
        for (int i = 0; i < 26; i++)
        {
            if (sorted[i] == 0)
                break;
            else
            {
                for (int j = 0; j < 26; j++)
                {
                    if (alphabet[j] == sorted[i])
                    {
                        int k = 0;
                        while (alphabet[j] != 0)
                        {
                            if (char(j + 97) == s[k] || ans[k] != '0')
                                k++;
                            else
                            {
                                ans[k] = char(j + 97);
                                alphabet[j]--;
                                k++;
                            }
                        }
                    }
                }
            }
        }

        cout << "Case #" << i + 1 << ": ";
        for (int i = 0; i < s.length(); i++)
            cout << ans[i];
        cout << "\n";
    }
    return 0;
}