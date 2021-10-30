#include <bits/stdc++.h>

using namespace std;

bool isPangram(string input){
    bool array[26] ={};
    for(char u:input){
        if(u >='a' && u<='z'){
            array[u-'a'] = true;
        } else if (u >='A' && u<='Z'){
            array[u-'A'] = true;
        }
    }
    for(int i=0; i<26; i++){
        if(!array[i]){
            return false;
        }
    }
    return true;
}
int main(){
    string input;
    cin >> input;
    if(isPangram(input)){
        cout << "TRUE";
    } else{ 
        cout << "FALSE";
    }
    return 0;
}