#include <iostream>
using namespace std;

int main(void){
    int row, column, min;
    cin>>row>>column;
    int arr[column];
    int min[row];
    
    for(int i = 0; i<row; i++){
        min = 0;
        for(int j = 0; j<column; j++){
            cin>>arr[j];
            if(arr[j]<min)
                min = arr[j];
        }
        min[i] = min;
    }
}