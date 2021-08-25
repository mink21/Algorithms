#include <iostream>
using namespace std;

int main(void)
{
    int n, cnt = 0, a, b;
    int arr[8];
    cin >> n;

    //put number into array
    while (n > 10)
    {
        arr[cnt] = n % 10;
        cnt++;
        n /= 10;
    }
    arr[cnt] = n;

    //calculate sum of each side
    a = 0;
    b = 0;
    for (int i = 0; i < cnt / 2 + 1; i++)
    {
        a += arr[i];
        b += arr[cnt - i];
    }

    //result
    if (a == b)
        cout << "LUCKY\n";
    else
        cout << "READY\n";
    return 0;
}