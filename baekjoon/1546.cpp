#include <iostream>
using namespace std;

void solve()
{
    int N, max = 0;
    cin >> N;
    float score[N];
    float sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> score[i];
        if (score[i] > max)
            max = score[i];
    }
    for (int i = 0; i < N; i++)
    {
        score[i] = score[i] / max * 100;
        sum += score[i];
    }
    printf("%.9f\n", sum / N);
}

int main(void)
{
    solve();
    return 0;
}