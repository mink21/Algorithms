#include <iostream>
using namespace std;

int main(void)
{
    int N;
    long long minPrice, sum;
    cin >> N;
    int road[N - 1];
    int price[N];
    for (int i = 0; i < N - 1; i++)
        cin >> road[i];
    for (int i = 0; i < N; i++)
        cin >> price[i];

    minPrice = price[0];
    sum = road[0] * minPrice;
    for (int i = 1; i < N - 1; i++)
    {
        if (price[i] < minPrice)
            minPrice = price[i];
        sum += road[i] * minPrice;
    }

    cout << sum << "\n";
    return 0;
}