#include <iostream>
#include <string>
using namespace std;

int n, m;
bool graph[1000][1000];

bool dfs(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if (!graph[x][y])
    {
        graph[x][y] = true;
        dfs(x - 1, y);
        dfs(x + 1, y);
        dfs(x, y - 1);
        dfs(x, y + 1);
        return true;
    }
    return false;
}

void print_arr()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j])
                cout << "1";
            else
                cout << "0";
        }
        cout << "\n";
    }
}

int main(void)
{
    cin >> n >> m;
    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            if (str[j] == '1')
                graph[i][j] = true;
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dfs(i, j))
            {
                //print_arr();
                //cout << "\n";
                result++;
            }
        }
    }

    cout << result << "\n";
    return 0;
}