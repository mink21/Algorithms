#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string alpha;
    cin >> alpha;

    int count = alpha.length();

    for (int i = 0; i < alpha.length(); i++)
    {
        if (alpha[i] == '=' | alpha[i] == '-')
            count--;
        else if (alpha[i] == 'z' && alpha[i - 1] == 'd' && alpha[i + 1] == '=')
            count--;
        else if (alpha[i] == 'j' && (alpha[i - 1] == 'l' | alpha[i - 1] == 'n'))
            count--;
    }

    cout << count << endl;

    return 0;
}