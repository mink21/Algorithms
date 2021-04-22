#include <iostream>
using namespace std;

int N, cnt = 0;
int ChessBoard[15];

void nqueen(int num, int idx)
{
    //NO
    for (int i = 1; i < idx; i++)
    {
        if (ChessBoard[i] == num || ChessBoard[i - 1] == num - 1 || ChessBoard[i - 1] == num + 1)
            return;
    }
    if (num > N)
        return;

    //YES
    if (idx == N)
    {
        for (int i = 0; i < idx; i++)
            cout << ChessBoard[i] << " ";
        cout << endl;
        cnt++;
        return;
    }

    //backtrack
    ChessBoard[idx] = num;
    nqueen(num + 1, idx + 1);
    nqueen(num + 1, idx);
    nqueen(num, idx + 1);
}

int main(void)
{
    cin >> N;
    nqueen(0, 0);
    return 0;
}