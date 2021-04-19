#include <iostream>
#include <string>
using namespace std;

int M, N, P;

int check(bool matrix[50][50], int index)
{
    int u, v, i, j;
    cin >> u >> v;

    //if someone doesnt know any managers
    /*i = 0;
    while (i < M)
    {
        if (i != u && matrix[u][i])
            break;
        i++;
        if (i == M)
            return -1;
    }
    i = 0;
    while (i < M)
    {
        if (i != v && matrix[v][i])
            break;
        i++;
        if (i == M)
            return -1;
    }*/

    //they already know each other
    if (matrix[u][v])
        return 0;

    //they know a manager
    i = 0;
    while (i < M)
    {
        if (matrix[u][i] && matrix[v][i])
            return index + 1;
        i++;
    }

    //recursive
    for (i = 0; i < M; i++)
    {
        if (matrix[u][i])
        {
            for (j = 0; j < M; j++)
            {
                if (matrix[i][j])
                {
                    matrix[u][j] = true;
                    matrix[j][u] = true;
                    check(matrix, index + 1);
                }
            }
        }
    }
    return -1;
}

void solve()
{
    string str;
    bool relations[50][50];

    cin >> M >> N >> P;
    for (int i = 0; i < M + N; i++)
    {
        cin >> str;
        for (int j = 0; j < M + N; j++)
        {
            if (str[j] == 'Y')
                relations[i][j] = true;
        }
    }

    int ans;
    for (int i = 0; i < P; i++)
    {
        ans = check(relations, 0);
        cout << ans << " ";
    }
}

int main(void)
{
    int test_case;
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}