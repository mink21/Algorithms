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

        if (x1 == x2)
        {
            if (y1 < y2)

                for (int i = y1; i <= y2; i++)
                    hydrothermal[x1][i]++;

            else

                for (int i = y2; i <= y1; i++)
                    hydrothermal[x1][i]++;
        }
        else if (y1 == y2)
        {
            if (x1 < x2)
                for (int i = x1; i <= x2; i++)
                    hydrothermal[i][y1]++;
            else
                for (int i = x2; i <= x1; i++)
                    hydrothermal[i][y1]++;
        }
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