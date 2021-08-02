#include <iostream>
using namespace std;

bool check(int h, int m, int s)
{
    if (h % 10 == 3 || m / 10 == 3 || m % 10 == 3 || s / 10 == 3 || s % 10 == 3)
        return true;
    return false;
}

int main(void)
{
    int N, count;
    cin >> N;

    count = 0;
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            for (int k = 0; k < 60; k++)
            {
                if (check(i, j, k))
                    count++;
            }
        }
    }

    cout << count << "\n";
    return 0;
}