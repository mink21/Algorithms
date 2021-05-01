#include <iostream>
using namespace std;

int main(void)
{
    int N, K, temp, count;
    cin >> N >> K;

    count = 0;
    while (N != 1)
    {
        if (N % K != 0)
        {
            temp = N / K * K;
            count += (N - temp);
            N = temp;
        }
        else
        {
            N /= K;
            count++;
        }
    }

    cout << count << "\n";
    return 0;
}
