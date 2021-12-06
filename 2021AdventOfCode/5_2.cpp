#include <iostream>
#include <string>

using namespace std;

void solve(void)
{
    int ans = 0;
    int hydrothermal[1000][1000] = {0};

    string str;
    while (true)
    {
        getline(cin, str);
        if (str == "")
            break;

        // parse string : x1
        string delimiter = ",";
        size_t pos = str.find(delimiter);
        string token = str.substr(0, pos);
        int x1 = stoi(token);
        str.erase(0, pos + delimiter.length());

        // parse string : y1
        delimiter = " -> ";
        pos = str.find(delimiter);
        token = str.substr(0, pos);
        int y1 = stoi(token);
        str.erase(0, pos + delimiter.length());

        // parse string: x2, y2
        delimiter = ",";
        pos = str.find(delimiter);
        token = str.substr(0, pos);
        int x2 = stoi(token);
        str.erase(0, pos + delimiter.length());
        int y2 = stoi(str);

        // directions
        int x[8] = {1, 1, 0, -1, -1, -1, 0, 1};
        int y[8] = {0, 1, 1, 1, 0, -1, -1, -1};
        int direction;

        // find direction
        if (x1 == x2)
        {
            if (y1 < y2)
                direction = 2;
            else
                direction = 6;
        }
        else if (y1 == y2)
        {
            if (x1 < x2)
                direction = 0;
            else
                direction = 4;
        }
        else
        {
            if (x2 > x1 && y2 > y1)
                direction = 1;
            else if (x2 < x1 && y2 > y1)
                direction = 3;
            else if (x2 < x1 && y2 < y1)
                direction = 5;
            else
                direction = 7;
        }

        // draw lines
        while (x1 != x2 || y1 != y2)
        {
            hydrothermal[x1][y1]++;
            x1 += x[direction];
            y1 += y[direction];
        }
        hydrothermal[x2][y2]++;
    }

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            // cout << hydrothermal[i][j] << " ";
            if (hydrothermal[i][j] > 1)
                ans++;
        }
        // cout << endl;
    }
    cout << ans << endl;
}

int main(void)
{
    solve();
    return 0;
}