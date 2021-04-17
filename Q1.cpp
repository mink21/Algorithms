#include <iostream>
#include <algorithm>
using namespace std;

int pets[100];
int treats[101];

int solve()
{
    int N, num = 1, sum = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> pets[i];
    }
    sort(pets, pets + N);
    for (int i = 0; i < N; i++)
    {
        sum += num;
        if (pets[i] == pets[i + 1])
            continue;
        num++;
    }
    return sum;
}

int main(void)
{
    int test_case, ans;
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        ans = solve();
        cout << "Case #" << i + 1 << ": " << ans << "\n";
    }
    return 0;
}