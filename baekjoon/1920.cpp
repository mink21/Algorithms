#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

void check(int n, int key)
{
    int start = 0;
    int end = n - 1;
    int mid;

    while (end - start >= 0)
    {
        mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            cout << "1"
                 << "\n";
            return;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    cout << "0"
         << "\n";
    return;
}

void solve()
{
    //read input
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    //calculate
    int M, temp;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> temp;
        check(N, temp);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}