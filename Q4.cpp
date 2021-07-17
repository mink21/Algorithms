#include <iostream>
#include <algorithm>
using namespace std;

int n, m, num, ans, max1, max2;
bool flag;
int arr[20001][6];

void readArray(int order, int num)
{
    int temp, min1 = 10000000, min2 = 10000000, min3 = 10000000, min4 = 10000000;
    for (int i = 0; i < num; i++)
    {
        cin >> temp;
        if (temp < min1)
        {
            min4 = min3;
            min3 = min2;
            min2 = min1;
            min1 = temp;
        }
        else if (temp < min2)
        {
            min4 = min3;
            min3 = min2;
            min2 = temp;
        }
        else if (temp < min3)
        {
            min4 = min3;
            min3 = temp;
        }
        else if (temp < min4)
        {
            min4 = temp;
        }
    }

    arr[order][0] = min1;
    arr[order][1] = min2;
    arr[order][2] = min3;
    arr[order][3] = min4;
    arr[order][4] = min1 + min2 + min3 + min4;
    arr[order][5] = num;

    if (arr[max1][4] < arr[order][4])
        max1 = order;
    else if (arr[max2][4] < arr[order][4])
        max2 = order;
}

void solve(void)
{
    ans = 0;
    max1 = 0;
    max2 = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        readArray(i, num);
    }
    for (int i = 0; i < n; i++)
    {
        if (flag == 0 && (arr[i][5] % 2 == 0))
        {
            ans += arr[i][4];
        }
        else if (flag == 0 && (arr[i][5] % 2 == 1))
        {
            flag = 1;
            ans += (arr[i][4] + arr[i][0]);
        }
        else if (flag == 1 && (arr[i][5] % 2 == 1))
        {
            flag = 0;
            ans += (arr[i][4] + arr[i][0]);
        }
        else
        {
            ans += (arr[i][4] + arr[i][0] + arr[i][1]);
        }
    }

    ans -= (arr[max1][2] + arr[max1][3] + arr[max2][2] + arr[max2][3]);
}

int main(void)
{
    int test_case;
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        solve();
        cout << "Case #" << i + 1 << "\n";
        cout << ans << "\n";
    }
}