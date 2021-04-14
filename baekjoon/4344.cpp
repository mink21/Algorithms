#include <iostream>
using namespace std;

void solve()
{
    int N, sum = 0, num = 0, mean;
    int score[1000] = {
        0,
    };
    float percent;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> score[i];
        sum += score[i];
    }
    mean = sum / N;
    for (int i = 0; i < N; i++)
    {
        if (score[i] > mean)
            num++;
    }
    percent = (float)num / N * 100;
    printf("%.3f%%\n", percent);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        solve();
    }
    return 0;
}