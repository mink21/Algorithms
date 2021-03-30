#include <iostream>
using namespace std;

//code for c

int count = 0;
int n;
int board[15];

int promissing(int cdx)
{
    for (int i = 0; i < cdx; i++)
    {
        if (board[cdx] == board[i] || cdx - i == abs(board[cdx] - board[i]))
            return 0;
    }
    return 1;
}

int nqueen(int cdx, int count)
{
    if (cdx == n)
    {
        count++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        board[cdx] = i;
        if (promissing(cdx))
        {
            nqueen(cdx + 1, count);
        }
    }
    return count;
}

int main()
{
    cin >> n;
    count = nqueen(0, 0);
    cout << count << endl;
}