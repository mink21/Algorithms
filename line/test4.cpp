#include <iostream>
#include <stdlib.h>
using namespace std;

long long int l, r, m;
long long int spell[10];

int main(int argc, char *argv[])
{
    l = atoll(argv[1]);
    r = atoll(argv[2]);
    m = atoll(argv[3]);

    for (int i = 0; i < m; i++)
    {
        spell[i] = atoll(argv[4 + i]);
        if (spell[i] == 1)
        {
            cout << "0\n";
            return 0;
        }
    }

    if (m == 1)
    {
        int temp = r / spell[0] - (l - 1) / spell[0];
        cout << r - l + 1 - temp << "\n";
        return 0;
    }

    long long int count = 0;
    if (r < 10000000)
    {
        bool visited[r];
        for (int i = l; i <= r; i++)
            visited[i] = false;

        for (int i = 0; i < m; i++)
        {
            int temp = (l / spell[i] + 1) * spell[i];
            while (temp <= r)
            {
                visited[temp] = true;
                temp += spell[i];
            }
        }

        for (int i = l; i <= r; i++)
        {
            if (!visited[i])
                count++;
        }
    }
    else
    {
        count = r - l + 1;
        for (int i = 0; i < m; i++)
        {
            int temp = r / spell[i] - (l - 1) / spell[i];
            count -= temp;
        }
    }

    cout << count << "\n";
    return 0;
}