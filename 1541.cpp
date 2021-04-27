#include <iostream>
#include <string>
using namespace std;

int main(void){
    int temp, sum, j = 0, min;
    int arr[50];
    string str;
    cin>>str;

    sum = 0;
    temp = 0;
    for(int i = 0; i<str.length(); i++){
        if(str[i] == '+'){
            sum += temp;
            temp = 0;
        }else if(str[i] == '-'){
            sum += temp;
            arr[j++] = sum;
            sum = 0;
            temp = 0;
        }else{
            temp *= 10;
            temp += (str[i]-'0');
        }
    }

    sum += temp;
    arr[j++] = sum;

    min = arr[0];
    for(int i = 1; i<j; i++){
        min -= arr[i];
    }

    cout<<min<<"\n";
    return 0;
}