#include <iostream>
#include <algorithm>
using namespace std;

void sort(int *arr)
{
}

void solve()
{
    //read input
    int N, M;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cin >> M;
    int arr2[M];
    for (int i = 0; i < M; i++)
    {
        cin >> arr2[i];
    }
    int flags[M];

    //calculate
    sort(arr2);
    for (int i = 0; i < M; i++)
    {
        flags[i] = 0;
        for (int j = 0; j < N; j++)
        {
            if (arr2[i] == arr[j])
            {
                flags[i] = 1;
            }
        }
    }

    //print output
    for (int i = 0; i < M; i++)
    {
        cout << flags[i] << "\n";
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