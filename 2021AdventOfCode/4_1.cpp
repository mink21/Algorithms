#include <iostream>
#include <string>

using namespace std;

int input[100];
int numOfInput, sum;
int bingoBoard[5][5];

void parseString(void)
{
    string s;
    cin >> s;
    string delimiter = ",";

    size_t pos = 0;
    string token;
    int idx = 0;
    while ((pos = s.find(delimiter)) != string::npos)
    {
        token = s.substr(0, pos);
        input[idx++] = stoi(token);
        s.erase(0, pos + delimiter.length());
    }
    input[idx++] = stoi(s);
    numOfInput = idx;
}

void printString(void)
{
    for (int i = 0; i < numOfInput; i++)
        cout << input[i] << endl;
}

void readBingoBoard(void)
{
    sum = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> bingoBoard[i][j];
            sum += bingoBoard[i][j];
        }
    }
}

void printBoard(void)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << bingoBoard[i][j] << " ";
        }
        cout << endl;
    }
}

void printboolBoard(bool board[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j])
                cout << 1 << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
}

bool checkBingo(bool board[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        if (board[i][0] && board[i][1] && board[i][2] && board[i][3] && board[i][4])
            return true;
        if (board[0][i] && board[1][i] && board[2][i] && board[3][i] && board[4][i])
            return true;
    }
    return false;
}

int checkBoard(void)
{
    bool boardCheck[5][5] = {0};
    int idx = 0;
    int temp;
    while (!checkBingo(boardCheck) || idx >= numOfInput)
    {
        temp = input[idx++];
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (bingoBoard[i][j] == temp)
                {
                    // cout << i << " " << j << " " << temp << endl;
                    boardCheck[i][j] = true;
                    sum -= temp;
                }
            }
        }
    }
    if (idx < numOfInput)
        return temp;
    else
        return 0;
}

void solve(void)
{
    parseString();
    // printString();
    int finalAns, finalSum;
    for (int i = 0; i < 100; i++)
    {
        readBingoBoard();
        // printBoard();
        if (i == 25)
        {
            finalAns = checkBoard();
            finalSum = sum;
        }
    }
    cout << finalAns << " " << finalSum << " " << finalAns * finalSum << endl;
}

int main(void)
{
    solve();
    return 0;
}