#include <iostream>
#include <string>

using namespace std;

int ans = 0;
string digits[10];
string output[4];
string signals = "abcdefg";

void parseString(string s){
    string delimiter = " ";
    size_t pos = 0;
    string token;
    for(int i = 0; i<9; i++){
        pos = s.find(delimiter);
        token = s.substr(0, pos);
        digits[i] = token;
        s.erase(0, pos+delimiter.length());
    }

    delimiter = " | ";
    pos = s.find(delimiter);
    token = s.substr(0, pos);
    digits[9] = token;
    s.erase(0, pos+delimiter.length());

    delimiter = " ";
    for(int i = 0; i<3; i++){
        pos = s.find(delimiter);
        token = s.substr(0, pos);
        output[i] = token;
        s.erase(0, pos+delimiter.length());        
    }
    output[3] = s;
}

void printInput(void){
    for(int i =  0; i<10; i++)
        cout<<digits[i]<<" ";
    cout<<endl;
    for(int i = 0;i<4; i++)
        cout<<output[i]<<" ";
    cout<<endl;
}

int getIndexFirst(int a, int b){
    string str;

    int firstLength = digits[a].length();
    int secondLength = digits[b].length();
    for(int i = 0; i<firstLength; i++){
        bool check;
        for(int j = 0; j<secondLength; j++){
            str = digits[a];
            int temp1 = str[i];
            str = digits[b];
            int temp2 = str[j];
            if(temp1 == temp2)
                check = true;
        }
        if(!check)
            return i;
    }
    return 0;
}

void findSignal(void){
    string str;

    //find signals for a (0)
    int a = getIndexFirst(7, 1);
    str = digits[7];
    signals[0] = str[a];

    //find signals for b (1)
    int b = getIndexFirst(9, 5);
    str = digits[9];
    signals[1] = str[b];

    //find signals for e (4)
    int e = getIndexFirst(6, 5);
    str = digits[6];
    signals[4] = str[e];

    //find signals for g (6)
    int g = getIndexFirst(8, 0);
    str = digits[8];
    signals[6] = str[g];

    //find signals for d (3)
    for(int i = 0; i<5; i++){
        string str = digits[2];
        char temp = str[i];
        if(temp != signals[0] && temp != signals[1] && temp != signals[4] && temp != signals[6]){
            signals[3] = temp;
            break;
        }
    }

    //find signals for c (2)
    for(int i = 0; i<3; i++){
        string str = digits[7];
        char temp = str[i];
        if(temp != signals[0] && temp != signals[1]){
            signals[2] = temp;
            break;
        }
    }

    //find signals for f (5)
    for(int i = 0; i<4; i++){
        string str = digits[4];
        char temp = str[i];
        if(temp != signals[1] && temp != signals[2] && temp != signals[6]){
            signals[5] = temp;
            break;
        }
    }  
}

void printSignal(void){
    for(int i = 0; i<7; i++)
        cout<<signals[i]<<" ";
    cout<<endl;
}

void solve(void){
    string s;
    while(true){
        getline(cin, s);
        if(s == "") break;
        parseString(s);
        //printInput();
        findSignal();
        printSignal();
    }
    cout<<ans<<endl;
}

int main(void){
    solve();
    return 0;
}