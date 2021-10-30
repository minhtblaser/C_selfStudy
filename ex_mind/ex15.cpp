#include <iostream>
#include <string>

using namespace std;

string truncateString(string s){
    bool kt = true;
    while (kt && s.length() > 0){
        kt = false;
        if ((s[0] - '0') % 3 ==0 ){
            kt = true;
            s.erase(0,1);
        }
        if ((s[s.length() - 1] - '0') % 3 == 0){
            kt = true;
            s.erase(s.length() - 1,1);
        } else {
            if ((s[s.length() - 1] + s[0]) % 3 == 0){
                kt = true;
                s.erase(s.length() - 1,1);
                s.erase(0,1);
            }
        }
    }
    return s;
}
int main(){
    string s;
    cin >> s;
    cout << truncateString(s);
    return 0;
}