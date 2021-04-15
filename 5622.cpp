#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char str[15];
    cin >> str;
    int i = 0, min = 0;
    while (str[i] > 64 && str[i] < 91)
    {
        if (str[i] < 68)
        {
            min += 3;
        }
        else if (str[i] < 71)
        {
            min += 4;
        }
        else if (str[i] < 74)
        {
            min += 5;
        }
        else if (str[i] < 77)
        {
            min += 6;
        }
        else if (str[i] < 80)
        {
            min += 7;
        }
        else if (str[i] < 84)
        {
            min += 8;
        }
        else if (str[i] < 87)
        {
            min += 9;
        }
        else
        {
            min += 10;
        }
        i++;
    }

    cout << min << endl;

    return 0;
}