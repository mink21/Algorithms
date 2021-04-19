#include <iostream>
using namespace std;

int main(void)
{
    //sync off
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //variable
    int N;
    int count = 1, x = 0, y = 0;
    int dx[4] = {1, -1, 0, 1};
    int dy[4] = {0, 1, 1, -1};
    int mode = 0;
    cin >> N;

    //calculate
    while (count != N)
    {
        count++;
        x += dx[mode];
        y += dy[mode];
        if (mode == 0 | mode == 2)
            mode++;
        else if (mode == 1 && x == 0)
            mode++;
        else if (mode == 3 && y == 0)
            mode = 0;
    }

    //output
    cout << y + 1 << "/" << x + 1 << endl;
    return 0;
}