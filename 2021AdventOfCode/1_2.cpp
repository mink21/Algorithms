#include <iostream>

using namespace std;

int main(void)
{
    int first, second, third, fourth, count = 0;
    cin >> first >> second >> third;
    while (true)
    {
        // input
        cin >> fourth;

        // calculate
        int sum1 = first + second + third;
        int sum2 = second + third + fourth;
        if (sum2 - sum1 > 0)
            count++;

        // break;
        if (fourth == 7739)
            break;

        // variables
        first = second;
        second = third;
        third = fourth;
    }
    cout << count << endl;
    return 0;
}