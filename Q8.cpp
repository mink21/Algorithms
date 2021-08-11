#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
    string str;
    char arr[10000];
    int num = 0, alp = 0;

    cin>>str;
    for(int i = 0; i<str.length(); i++){
        int temp = int(str[i]);
        if((65<=temp) && (temp<=90)){
            arr[alp] = str[i];
            alp++;
        }else
            num += (temp - 48);
    }
    sort(arr, arr+alp);
    
    for(int i = 0; i<alp; i++)
        cout<<arr[i];
    cout<<num<<"\n";
    return 0;
}