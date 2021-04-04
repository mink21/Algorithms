#include <iostream>
using namespace std;

int w[21][21][21];

void calculate()
{
    w[0][0][0] = 1;
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            for (int k = 0; k < 21; k++)
            {
                if (i == 0 || j == 0 || k == 0)
                    w[i][j][k] = 1;
                else if (i < j && j < k)
                    w[i][j][k] = w[i][j][k - 1] + w[i][j - 1][k - 1] - w[i][j - 1][k];
                else
                    w[i][j][k] = w[i - 1][j][k] + w[i - 1][j - 1][k] + w[i - 1][j][k - 1] - w[i - 1][j - 1][k - 1];
            }
        }
    }
}

void recursive(int A, int B, int C)
{
    if (A <= 0 || B <= 0 || C <= 0)
        cout << "w(" << A << ", " << B << ", " << C << ") = " << w[0][0][0] << endl;
    else if (A > 20 || B > 20 || C > 20)
        cout << "w(" << A << ", " << B << ", " << C << ") = " << w[20][20][20] << endl;
    else
        cout << "w(" << A << ", " << B << ", " << C << ") = " << w[A][B][C] << endl;
}

int main(void)
{
    int A, B, C;
    calculate();
    cin >> A >> B >> C;
    while (A != -1 || B != -1 || C != -1)
    {
        recursive(A, B, C);
        cin >> A >> B >> C;
    }
    return 0;
}

/*
//by rama0126

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int d[21][21][21] = { 0, };
int w(int a, int b, int c);
int main() {
    int a, b, c;
    d[20][20][20]= 1048576;
    d[0][0][0] = 1;
    while (1) {
        scanf("%d%d%d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1)break;
        
        printf("w(%d, %d, %d) = %d\n", a, b, c,w(a,b,c));
    }
}
int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return d[0][0][0];
    }
    if (a > 20 || b > 20 || c > 20) {
        return d[20][20][20];
    }
    if (d[a][b][c] != 0)return d[a][b][c];
    if (a < b && b < c) {
        d[a][b][c]= w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        return d[a][b][c];
    }
    d[a][b][c]= w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    return d[a][b][c];
}
*/