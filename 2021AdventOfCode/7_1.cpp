#include <iostream>
#include <string>

using namespace std;

int crab[2000] = {0};
int maxHorizontal = 0;

void readInput(void)
{
    string s;
    getline(cin, s);

    string delimiter = ",";
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos)
    {
        token = s.substr(0, pos);
        int temp = stoi(token);
        if (temp > maxHorizontal)
            maxHorizontal = temp;
        crab[temp]++;
        s.erase(0, pos + delimiter.length());
    }
    int temp = stoi(s);
    if (temp > maxHorizontal)
        maxHorizontal = temp;
    crab[temp]++;
}

int calculateCost(int pos)
{
    int cost = 0;
    for (int i = 0; i < maxHorizontal + 1; i++)
    {
        for (int j = 0; j < crab[i]; j++)
        {
            cost += abs(i - pos);
        }
    }
    return cost;
}

void solve(void)
{
    for (int i = 0; i < 5; i++)
        readInput();
    int minCost = 1000000000;
    for (int i = 0; i < maxHorizontal + 1; i++)
    {
        int temp = calculateCost(i);
        // cout << i << " " << temp << endl;
        if (temp < minCost)
            minCost = temp;
    }
    cout << minCost << endl;
}

int main(void)
{
    solve();
    return 0;
}