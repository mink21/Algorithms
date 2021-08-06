#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int n, target;
    int arr[1000];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    target = 1;
    for (int i = 0; i < n; i++)
    {
        if (target < arr[i])
            break;
        target += arr[i];
    }

    cout << target << "\n";
    return 0;
}