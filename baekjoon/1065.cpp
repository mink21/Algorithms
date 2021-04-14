#include <iostream>
using namespace std;

int solve(int N)
{
    int answer, count = 99;
    if (N < 100)
    {
        return N;
    }
    else
    {
        for (int i = 100; i <= N; i++)
        {
            if ((i % 10 - (i / 10) % 10) == ((i / 10) % 10 - i / 100))
            {
                count++;
            }
        }
        return count;
    }
}

int main(void)
{
    int N, answer;
    cin >> N;
    answer = solve(N);
    cout << answer << "\n";
    return 0;
}