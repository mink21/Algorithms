#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> lanternfish;

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
        lanternfish.push_back(temp);
    }
    int temp = stoi(str);
    lanternfish.push_back(temp);
}

void spawn(void)
{
    for (int i = 0; i < lanternfish.size(); i++)
    {
        if (lanternfish[i] == 0)
        {
            lanternfish[i] = 6;
            lanternfish.push_back(9);
        }
        else
        {
            lanternfish[i]--;
        }
    }
}

void printFish(void)
{
    for (int i = 0; i < lanternfish.size(); i++)
    {
        cout << lanternfish[i] << " ";
    }
    cout << endl;
}

void solve(void)
{
    readInput();
    for (int i = 0; i < 80; i++)
    {
        // cout << "After " << i + 1 << " day: ";
        spawn();
        // printFish();
    }
    cout << lanternfish.size() << endl;
}

int main(void)
{
    solve();
    return 0;
}