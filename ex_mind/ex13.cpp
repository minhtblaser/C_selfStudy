#include <iostream>
string formatString (string s){
    if (s[0] == " "){
        s.erase(0,1);
    }
    if (s[s.length()-1] == " "){
        s.erase(s.length()-1,1);
    }
    while (s.find("  ") != -1){
        s.erase("  ", 1);
    }
    return input;
}