#include <iostream>
#include <string>

using namespace std;

bool isValid(string input){
    string s = input;
    if (s.length() % 2 != 0) return false;
    if (s.substr(0,s.length()/2) == s.substr(s.length()/2, s.length()/2)){
        return true;
    }
    return false;
}
int main(){
    string input;
    cin >> input;
    if(isValid(input)){
        cout << "This is tandemRepeat";
    } else {
        cout << "this is not tandemrepeat";
    }
    return 0;
}