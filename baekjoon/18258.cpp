//백준 18258 번

#include <iostream>
#include <string>
#include <queue>
using namespace std;

string str;
queue<int> q;

void solve()
{
    int temp;
    cin >> str;
    if (str == "push")
    {
        cin >> temp;
        q.push(temp);
    }
    else if (str == "pop")
    {
        if (q.empty())
        {
            cout << "-1\n";
        }
        else
        {
            temp = q.front();
            cout << temp << "\n";
            q.pop();
        }
    }
    else if (str == "size")
    {
        temp = q.size();
        cout << temp << "\n";
    }
    else if (str == "empty")
    {
        if (q.empty())
        {
            cout << "1\n";
        }
        else
        {
            cout << "0\n";
        }
    }
    else if (str == "front")
    {
        if (q.empty())
        {
            cout << "-1\n";
        }
        else
        {
            temp = q.front();
            cout << temp << "\n";
        }
    }
    else if (str == "back")
    {
        if (q.empty())
        {
            cout << "-1\n";
        }
        else
        {
            temp = q.back();
            cout << temp << "\n";
        }
    }
    else
    {
        cout << "error\n";
    }
}

int main(void)
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    int test_case;
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        solve();
    }
    return 0;
}