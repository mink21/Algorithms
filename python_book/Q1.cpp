#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int n, ans, temp;
    int arr[100000];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    ans = 0;
    temp = n - 1;
    while (n > 0)
    {
        ans++;
        n -= arr[temp];
        temp--;
    }

    cout << ans << "\n";
    return 0;
}