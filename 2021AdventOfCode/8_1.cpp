#include <iostream>
#include <string>

using namespace std;

void solve(void){
    int ans = 0;
    string s;

    while(true){
        string delimiter = " | ";
        size_t pos = 0;
        string token;
        getline(cin, s);
        if(s == "") break;

        pos = s.find(delimiter);
        s.erase(0, pos+delimiter.length());

        delimiter = " ";
        for(int i = 0; i<3; i++){
            pos = s.find(delimiter);
            token = s.substr(0, pos);
            int length = token.length();
            if(length == 2 || length == 3 || length == 4 || length == 7)
                ans++;
            //cout<<token<<" "<<length<<" "<<ans<<endl;
            s.erase(0, pos+delimiter.length());
        }
        int length = s.length();
        if(length == 2 || length == 3 || length == 4 || length == 7)
            ans++;
        //cout<<s<<" "<<length<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
}

int main(void){
    solve();
    return 0;
}