#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string S;
    getline(cin, S);
    int count = 1;
    for (int i = 1; i < S.length() - 1; i++)
    {
        if (S[i] == ' ')
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}