#include <iostream>
#include <stack>

using namespace std;

int main(void){
    while(true){
        stack <char> st;
        string s;
        getline(cin, s);

        //finish input if only . is inputed
        if(s == "."){
            break;
        }

        //check if balanced
        int flag = 0;
        for(int i = 0; i<s.size(); i++){
            char c = s[i];
            if(c == '(' || c == '['){
                st.push(c);
            }else if(c == ')'){
                if(st.empty() || st.top() != '('){
                    flag = 1;
                    break;
                }
                st.pop();
            }else if(c == ']'){
                if(st.empty() || st.top() != '['){
                    flag = 1;
                    break;
                }
                st.pop();
            }
        }

        //output
        if(flag || !st.empty()) cout<<"no\n";
        else cout<<"yes\n";
    }
    return 0;
}