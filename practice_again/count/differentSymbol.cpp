#include <bits/stdc++.h>

using namespace std;

int differentSymbol(string s){
    int count = 0;
    vector<bool>check(256,false);
    for(int i=0; i<s.length(); i++){
        check[s[i]] = true;
    }    
    for(int i=0; i<s.length(); i++){
        if(check[s[i]]){
            count++;
            check[s[i]] = false;
        }
    }
    return count;
}
int main(){
    string input;
    getline(std::cin, input);
    cout << differentSymbol(input) << endl;
    return 0;
}