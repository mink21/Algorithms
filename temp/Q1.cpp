#include <iostream>

using namespace std;

int solve()
{
    int n, ans = 0, temp, d_temp;
    cin >> n;
    int dArray[100001] = {};
    bool visited[100001] = {};
    for (int i = 1; i < n + 1; i++)
    {
        cin >> dArray[i];
    }

    for (int i = 1; i < n + 1; i++)
    {
        if (visited[i] == 1)
            continue;
        else
        {
            ans++;
            visited[i] = 1;
            temp = i;
            d_temp = dArray[temp];
            if ((temp + d_temp < n + 1) && (visited[temp + d_temp] == 1))
                ans--;

            while ((temp + d_temp < n + 1) && (visited[temp + d_temp] == 0))
            {
                visited[temp + d_temp] = 1;
                temp = temp + d_temp;
                d_temp = dArray[temp];
                if ((temp + d_temp < n + 1) && (visited[temp + d_temp] == 1))
                    ans--;
            }
        }
    }
    return ans;
}

int main(int argc, char **argv)
{
    int test_case, answer;
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        answer = solve();
        cout << "Case #" << i + 1 << "\n"
             << answer << "\n";
    }
    return 0;
}