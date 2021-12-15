#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

int n, q;
map<int, pair<int, int>> gymnast; // num, (low, high);

void readInput(void)
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        gymnast.insert(make_pair(i, make_pair(l, r)));
    }
}

void printVector(void)
{
    for (int i = 0; i < gymnast.size(); i++)
        cout << gymnast[i].first << " " << gymnast[i].second.first << " " << gymnast[i].second.second << endl;
}

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    if (a.second.second == b.second.second)
        return a.first < b.first;
    return a.second.second > b.second.second;
}

// if score is same, by order
int queryTwo(int x)
{
    if (x == n)
        return n;

    int ans = 0;
    int low = lowScores[n - x];
    for (int i = 0; i < n; i++)
    {
        int high = gymnast[i].second;
        if (high == low)
        {
        }
        else if (high > low)
            ans++;
    }
    return ans;
}

void readQuery(void)
{
    int t, x, l, r;
    cin >> t;
    if (t == 1)
    {
        cin >> x >> l >> r;
        map<int, pair<int, int>>::iterator it = gymnast.find(x);
        gymnast.erase(it);
        gymnast.insert(make_pair(x, make_pair(l, r)));
        // printVector();
    }
    else
    {
        cin >> x;
        int ans = queryTwo(x);
        cout << ans << endl;
    }
}

int main(void)
{
    readInput();
    // sort(gymnast.begin(), gymnast.end(), compare);
    for (int i = 0; i < q; i++)
        readQuery();
    return 0;
}