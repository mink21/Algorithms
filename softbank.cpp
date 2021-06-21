#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    int n, m, k, answer, idx;
    cin >> n >> m >> k;
    int input[n][m];
    int bombed[n][m];
    int arr[n * m];

    //read input
    int bombFlag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char temp;
            cin >> temp;
            if (temp == 'B')
            {
                input[i][j] = 0;
                bombed[i][j] = 0;
                arr[i * m + j] = 0;
                bombFlag = 1;
            }
            else
            {
                input[i][j] = (int)temp - 48;
                bombed[i][j] = (int)temp - 48;
                arr[i * m + j] = (int)temp - 48;
            }
        }
    }

    //exception 1
    if ((n == 1 || m == 1) && bombFlag == 1)
    {
        cout << "0\n";
        return 0;
    }

    //bomb bombed array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (input[i][j] == 0)
            {
                for (int l = 0; l < n; l++)
                    bombed[l][j] = 0;
                for (int l = 0; l < m; l++)
                    bombed[i][l] = 0;
            }
        }
    }

    //exception 2
    if (k == 0)
    {
        answer = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                answer += bombed[i][j];
            }
        }
        cout << answer << "\n";
        return 0;
    }

    //sort input
    sort(arr, arr + n * m);

    //exception 3
    if (k > n * m)
    {
        int idx = n * m - 1;
        answer = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                answer += arr[idx--];
            }
        }
        cout << answer << "\n";
        return 0;
    }

    //calculate changes
    idx = n * m - 1;
    while (k > 0)
    {
        int min = 10;
        int i_pos = 0, j_pos = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((bombed[i][j] != 0) && (bombed[i][j] < min))
                {
                    min = bombed[i][j];
                    i_pos = i;
                    j_pos = j;
                }
            }
        }
        if (arr[idx] < min)
            break;
        else
            bombed[i_pos][j_pos] = arr[idx--];
        k--;
    }

    //find sum
    answer = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            answer += bombed[i][j];
        }
    }
    cout << answer << "\n";
    return 0;
}
