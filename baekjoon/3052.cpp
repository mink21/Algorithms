#include <iostream>
using namespace std;

void solve()
{
    int input, answer = 0;
    int check[42] = {
        0,
    };
    for (int i = 0; i < 10; i++)
    {
        cin >> input;
        check[input % 42] = 1;
    }
    for (int i = 0; i < 42; i++)
    {
        if (check[i] == 1)
        {
            answer++;
        }
    }
    cout << answer << "\n";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}