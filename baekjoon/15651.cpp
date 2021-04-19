#include <iostream>
using namespace std;

int N, M;
int num[8];

void solve(int n, int count)
{
    if (count == M)
    {
        for (int i = 0; i < M; i++)
            cout << num[i] << " ";
        cout << endl;
    }
    if (n > N)
        return;

    num[count] = n;
    solve(n, count + 1);
    solve(n + 1, count + 1);
    solve(n + 1, count);
}

int main(void)
{
    cin >> N >> M;
    solve(1, 0);
    return 0;
}