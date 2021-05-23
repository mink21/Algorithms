#include <iostream>
using namespace std;

long long int l, r, m, answer, temp;
long long int spell[10];

int lcm(int a, int b)
{
    int hcf, lcm;
    hcf = a;
    temp = b;
    while (hcf != temp)
    {
        if (hcf > temp)
            hcf -= temp;
        else
            temp -= hcf;
    }
    lcm = (a * b) / hcf;
    return lcm;
}

int main(void)
{
    cin >> l >> r >> m;
    for (int i = 0; i < m; i++)
        cin >> spell[i];

    int answer = r - l + 1;
    for (int i = 0; i < m; i++)
    {
        temp = r / spell[i] - l / spell[i];
        answer -= temp;
    }

    for (int i = 0; i < m; i++)
    {
        int tmp;
        if (i == m - 1)
        {
            tmp = lcm(spell[i], spell[1]);
            temp = r / tmp - l / tmp;
        }
        else
        {
            tmp = lcm(spell[i], spell[i + 1]);
            temp = r / tmp - l / tmp;
        }
        answer += temp;
    }
    cout << answer << "\n";
    return 0;
}