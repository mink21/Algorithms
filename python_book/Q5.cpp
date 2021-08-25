#include <iostream>
using namespace std;

int calculateP(int n)
{
    return n * (n - 1) / 2;
}

int main(void)
{
    int n, m, temp, ans;
    int arr[11] = {0};
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr[temp]++;
    }

    ans = calculateP(n);
    for (int i = 1; i <= m; i++)
        ans -= calculateP(arr[i]);

    cout << ans << "\n";
    return 0;
}