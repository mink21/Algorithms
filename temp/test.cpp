#include <iostream>
#include <string>

using namespace std;

void solve()
{
    int W_mark, R_mark, min, count, i;
    string Flowers;
    cin >> Flowers;

    //find the most rightest W
    W_mark = 0;
    for (i = 0; i < Flowers.length(); i++)
    {
        if (Flowers[i] == 'W')
            W_mark = i;
    }

    //count changing all R left of W_mark to W
    count = 0;
    for (i = 0; i < W_mark; i++)
    {
        if (Flowers[i] == 'R')
            count++;
    }
    min = count;

    //find the most leftest R
    R_mark = 0;
    i = 0;
    if (Flowers[0] == 'R')
    {
        R_mark = 0;
    }
    else
    {
        while (R_mark == 0 && i < Flowers.length())
        {
            if (Flowers[i] == 'R')
                R_mark = i;
            i++;
        }
    }

    //count changing all W right of R_mark to R
    count = 0;
    for (i = R_mark; i < Flowers.length(); i++)
    {
        if (Flowers[i] == 'W')
            count++;
    }
    if (min > count)
        min = count;

    cout << min << endl;
}

int main(void)
{
    int test_case;
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        solve();
    }
    return 0;
}
