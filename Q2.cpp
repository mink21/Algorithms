#include <iostream>
using namespace std;

int L[101];
char str[2501];

void solve()
{
    int N, size = 1, idx = 0;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> L[i];
        size += L[i];
    }
    str[idx++] = 'A';
    for (int i = 1; i <= N; i++)
    {
        //odd block
        if (i % 2 == 1)
        {
            while (L[i] > 1)
            {
                str[idx] = str[idx - 1] + 1;
                L[i]--;
                idx++;
            }
            //last char of odd block
            if (i == N)
            {
                str[idx] = str[idx - 1] + 1;
            }
            else if (str[idx - 1] + 1 > (65 + L[i + 1]))
            {
                str[idx] = str[idx - 1] + 1;
                idx++;
            }
            else
            {
                str[idx] = 65 + L[i + 1];
                idx++;
            }
        }
        //even block
        else
        {
            while (L[i] > 0)
            {
                str[idx] = 64 + L[i];
                L[i]--;
                idx++;
            }
        }
    }

    for (int i = 0; i < size; i++)
        cout << str[i];
}

int main(void)
{
    int test_case;
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}