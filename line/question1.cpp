#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n, q;
vector<pair<int, int>> gymnast;

void readInput(void)
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        gymnast.push_back(make_pair(l, r));
    }
}

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

// if score is same, by order
int queryTwo(int x)
{
    if (x == n)
        return n;

    int ans = 1;

    int low = 0;
    int index = 1234567890;
    if (x == 1)
    {
        for (int i = 0; i < n; i++)
        {
            int temp = gymnast[i].first;
            if (temp == low)
            {
                if (i < index)
                    index = i;
            }
            else if (temp > low)
            {
                low = gymnast[i].first;
                index = i;
            }
        }
    }
    else
    {
        vector<pair<int, int>> lowScore; // low, index;
        for (int i = 0; i < n; i++)
        {
            int temp = gymnast[i].first;
            lowScore.push_back(make_pair(temp, i));
        }
        sort(lowScore.begin(), lowScore.end(), compare);
        low = lowScore[x - 1].first;
        index = lowScore[x - 1].second;
    }

    for (int i = 0; i < n; i++)
    {
        if (index == i)
            continue;

        int high = gymnast[i].second;
        if (high == low)
        {
            if (i < index)
                ans++;
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
        gymnast[x - 1].first = l;
        gymnast[x - 1].second = r;
        // printVector();
    }
    else
    {
        cin >> x;
        int ans = queryTwo(x);
        cout << ans << "\n";
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    readInput();
    for (int i = 0; i < q; i++)
        readQuery();
    return 0;
}