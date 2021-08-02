#include <iostream>
#include <string>
using namespace std;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main(void)
{
    //read input
    string place;
    cin >> place;
    int nx = place[0] - 97;
    int ny = place[1] - '1';

    //calculate
    int x_temp, y_temp;
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        x_temp = nx + dx[i];
        y_temp = ny + dy[i];
        if (x_temp > -1 && x_temp < 8 && y_temp > -1 && y_temp < 8)
            count++;
    }

    //output
    cout << count << "\n";
    return 0;
}