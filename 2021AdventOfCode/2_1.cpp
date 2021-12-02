#include <iostream>
#include <string>

using namespace std;

int main(void){
    string com;

    int horizontal = 0, depth = 0;
    while(true){
        getline(cin, com);
        if(com == "")
            break;

        if(com[0] == 'f'){
            horizontal += com[8] - '0';
        }else if(com[0] == 'd'){
            depth += com[5] - '0';
        }else{
            depth -= com[3] -'0';
        }
    }

    cout<<horizontal*depth<<endl;
    return 0;
}