#include <iostream>
#include <cmath>
#define MAX 1000000

using namespace std;

bool isPrime[MAX + 1];

void sieveOfEratosthenes(void)
{
    for (int i = 2; i < MAX + 1; i++)
    {
        isPrime[i] = true;
    }

    int sqrtn = sqrt(MAX);
    for (int i = 2; i < sqrtn + 1; i++)
    {
        if (!isPrime[i])
            continue;
        for (int j = i + i; j < MAX + 1; j += i)
        {
            isPrime[j] = false;
        }
    }
}

void solve(void)
{
    int m, n;
    cin >> m >> n;

    sieveOfEratosthenes();
    for (int i = m; i < n + 1; i++)
    {
        if (isPrime[i])
        {
            cout << i << "\n";
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}