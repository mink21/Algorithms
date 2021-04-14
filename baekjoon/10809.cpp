#include <iostream>
using namespace std;

int main(void)
{
    //declaration
    int cnt = 0, temp;
    char s[100] = {};
    int mark[26];
    for (int i = 0; i < 26; i++)
        mark[i] = -1;

    //calculation
    cin >> s;
    while (s[cnt] - 'a' >= 0)
    {
        temp = s[cnt] - 'a';
        if (mark[temp] == -1)
            mark[temp] = cnt;
        cnt++;
    }

    //output
    for (int i = 0; i < 26; i++)
    {
        cout << mark[i] << " ";
    }
    cout << endl;
    return 0;
}