#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int w[21][21][21] = {
    0};

int recursive(int A, int B, int C)
{
    if (A <= 0 || B <= 0 || C <= 0)
        return w[0][0][0];
    if (A > 20 || B > 20 || C > 20)
        return w[20][20][20];
    if (w[A][B][C] != 0)
        return w[A][B][C];
    if (A < B && B < C)
    {
        w[A][B][C] = recursive(A, B, C - 1) + recursive(A, B - 1, C - 1) - recursive(A, B - 1, C);
        return w[A][B][C];
    }
    w[A][B][C] = recursive(A - 1, B, C) + recursive(A - 1, B - 1, C) + recursive(A - 1, B, C - 1) - recursive(A - 1, B - 1, C - 1);
    return w[A][B][C];
}

int main(void)
{
    int A, B, C;
    w[0][0][0] = 1;
    w[20][20][20] = 1048576;
    while (1)
    {
        cin >> A >> B >> C;
        if (A == -1 && B == -1 && C == -1)
            break;
        cout << "w(" << A << ", " << B << ", " << C << ") = " << recursive(A, B, C) << endl;
    }

    return 0;
}