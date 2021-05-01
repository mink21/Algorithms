#include <iostream>
using namespace std;

int main(void)
{
    int row, column;
    int min, max, temp;
    cin >> row >> column;

    max = 0;
    for (int i = 0; i < row; i++)
    {
        min = 10001;
        for (int j = 0; j < column; j++)
        {
            cin >> temp;
            if (temp < min)
                min = temp;
        }
        if (min > max)
            max = min;
    }

    cout << max << "\n";
    return 0;
}