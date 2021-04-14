#include <iostream>
using namespace std;

bool num[10001];

int check(int num)
{
    int sum = num;
    while (num != 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main(void)
{
    for (int i = 1; i < 10001; i++)
    {
        int a = check(i);
        if (a < 10001)
            num[a] = true;
    }
    for (int i = 1; i < 10001; i++)
    {
        if (!num[i])
            cout << i << endl;
    }
    return 0;
}