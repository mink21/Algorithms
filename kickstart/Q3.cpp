#include <iostream>
#include <cmath>
using namespace std;

int N = 10000;
bool isPrime[10001];
int R[1000];

void findPrimes()
{
    for (int i = 2; i < N + 1; i++)
        isPrime[i] = 1;

    int sqrtn = sqrt(N);
    for (int i = 2; i <= sqrtn; i++)
    {
        if (!isPrime[i])
            continue;
        for (int j = i * 2; j < N + 1; j += i)
            isPrime[j] = 0;
    }
}

void findR()
{
    int index = 0;
    for (int i = 2; i < N + 1; i++)
    {
        if (!isPrime[i])
            continue;
        else
            R[index++] = i;
    }
    for (int i = 0; i < 1000; i++)
        R[i] = R[i] * R[i + 1];
}

int solve()
{
    int Z, idx = 0;
    cin >> Z;
    while (R[idx] <= Z)
    {
        idx++;
    }
    idx = idx - 1;
    return R[idx];
}

int main(void)
{
    int test_case, answer;
    cin >> test_case;
    findPrimes();
    findR();
    for (int i = 1; i <= test_case; i++)
    {
        answer = solve();
        cout << "Case #" << i << ": " << answer << "\n";
    }
    return 0;
}