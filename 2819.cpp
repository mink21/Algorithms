#include <iostream>
#include <set>
using namespace std;

int arr[4][4];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
set<int> setary;

void dfs(int x, int y, int val, int depth)
{
    if (depth == 7)
    {
        setary.insert(val);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx > 3 || ny < 0 || ny > 3)
        {
            continue;
        }
        dfs(nx, ny, val * 10 + arr[nx][ny], depth + 1);
    }
}

int solve(void)
{
    setary.clear();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            dfs(i, j, arr[i][j], 1);
        }
    }
    return setary.size();
}

int main(void)
{
    int test_case, ans;
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        ans = solve();
        cout << "#" << i + 1 << " " << ans << "\n";
    }
    return 0;
}