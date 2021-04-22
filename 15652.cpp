#include <iostream>
using namespace std;

int N, M;
int arr[8];

void solve(int num, int index)
{
    if (index == M)
    {
        for (int i = 0; i < index; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    if (num > N)
        return;

    arr[index] = num;
    solve(num, index + 1);
    solve(num + 1, index);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    solve(1, 0);
    return 0;
}