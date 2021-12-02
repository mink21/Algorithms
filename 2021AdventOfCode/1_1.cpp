#include <iostream>

using namespace std;

int main(void)
{
    int first, second, count = 0;
    cin >> first;
    while (true)
    {
        cin >> second;
        if (second == 7739)
            break;
        if (second - first > 0)
            count++;
        first = second;
    }
    cout << count << endl;
    return 0;
}