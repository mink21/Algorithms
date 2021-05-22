#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string line;
    while (getline(cin, line))
    {
        cout << "Hello " << line << "!\n";
    }
    return 0;
}
