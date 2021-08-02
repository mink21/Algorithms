#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    //read input
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    //read and perform query
    int q, queryType, queryData[4], answer;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> queryType;
        if (queryType == 1)
        {
            cin >> queryData[0] >> queryData[1];
            a[queryData[0]] = queryData[1];
        }
        else
        {
            answer = 0;
            cin >> queryData[0] >> queryData[1] >> queryData[2] >> queryData[3];
            for (int k = 0; k < n; k++)
            {
                cout << a[k] << " ";
            }
            for (int j = queryData[0]; j <= queryData[1]; j++)
            {
                if (a[j] >= queryData[2] && a[j] <= queryData[3])
                    answer++;
            }
            cout << answer << "\n";
        }
    }

    return 0;
}
