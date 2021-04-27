#include <iostream>
using namespace std;

int N, M;
int num[7];

void func(int index)
{
    if (index == M)
    {
        for (int i = 0; i < M; i++)
            cout << num[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        num[index] = i;
        func(index + 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    func(0);
    return 0;
}