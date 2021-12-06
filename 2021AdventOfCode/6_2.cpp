#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long lanternfish[9] = {};

void readInput(void)
{
    string str;
    getline(cin, str);

    string delimiter = ",";
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != string::npos)
    {
        token = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
        int temp = stoi(token);
        lanternfish[temp]++;
    }
    int temp = stoi(str);
    lanternfish[temp]++;
}

void spawn(void)
{
    long long temp = lanternfish[0];
    for (int i = 0; i < 8; i++)
    {
        lanternfish[i] = lanternfish[i + 1];
    }
    lanternfish[6] += temp;
    lanternfish[8] = temp;
}

void printFish(void)
{
    for (int i = 0; i < 9; i++)
        cout << lanternfish[i] << " ";
    cout << endl;
}

long long findFishSize(void)
{
    long long ans = 0;
    for (int i = 0; i < 9; i++)
        ans += lanternfish[i];
    return ans;
}

void solve(void)
{
    readInput();
    for (int i = 0; i < 256; i++)
    {
        spawn();
        // printFish();
    }
    long long ans = findFishSize();
    cout << ans << endl;
}

int main(void)
{
    solve();
    return 0;
}