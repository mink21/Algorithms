#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int board[9][9];
vector<pair<int,int>> emptySlots;
int count = 0;
bool foundFlag = 0;

void printBoard(void){
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool check(pair<int, int> a){
    int x = a.first;
    int y = a.second;
    for(int i = 0; i<9; i++){
        if(board[x][i] == board[x][y] && i!=y)
            return false;
        if(board[i][y] == board[x][y] && i!=x)
            return false;
    }
    
    int squareX = x/3;
    int squareY = y/3;
    for(int i = 3*squareX; i<3*(squareX+1); i++){
        for(int j = 3*squareY; j<3*(squareY+1); j++){
            if(board[i][j] == board[x][y] && i!=x && j!=y)
                return false;
        }
    }
    return true;
}

void sudoku(int level){
    if(level == count){
        printBoard();
        foundFlag = true;
        return;
    }
    
    int x = emptySlots[level].first;
    int y = emptySlots[level].second;
    for(int i = 1; i<10; i++){
        board[x][y] = i;
        if(check(emptySlots[level]))
            sudoku(level+1);
        if(foundFlag)
            return;
    }
    
    board[x][y] = 0;
    return;
}

void solve(void){
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            int temp;
            cin>>temp;
            board[i][j] = temp;
            if(temp == 0){
                emptySlots.push_back(make_pair(i, j));
                count++;
            }
        }
    }
    sudoku(0);
}

int main(void){
    solve();
    return 0;
}