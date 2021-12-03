#include <iostream>
#include <string>

using namespace std;

void solve(void){
    int oneCount[12] = {0};
    int length = 0;

    string str;
    int stringlen;
    while(true){
        length++;

        getline(cin, str);
        if(str =="")
            break;
        
        stringlen = str.size();
        for(int i = 0; i<stringlen; i++){
            if(str[i] == '1'){
                oneCount[i]++;
            }
        }
    }

    //gamma
    for(int i = 0; i<stringlen; i++){
        if(oneCount[i]>=length/2){
            cout<<"1";
        }else{
            cout<<"0";
        }
    }
    cout<<endl;
}

int main(void){
    solve();
    return 0;
}