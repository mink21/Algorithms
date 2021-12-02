#include <iostream>
#include <string>

using namespace std;

int main(void){
    string com;
    int horizontal = 0, depth = 0, aim = 0;

    while(true){
        getline(cin, com);
        if(com == "")
            break;

        if(com[0] == 'f'){
            int x = com[8] - '0';
            horizontal += x;
            depth += aim*x;
        }else if(com[0] == 'd'){
            aim += com[5] - '0';
        }else{
            aim -= com[3] -'0';
        }
    }

    cout<<horizontal*depth<<endl;
    return 0;
}