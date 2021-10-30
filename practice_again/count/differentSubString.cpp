#include <bits/stdc++.h>

using namespace std;

int differentSubstring(string s){
    int n = s.length();
    return (n*(n+1))/2;
}
int main(){
    string s;
    getline(std::cin, s);
    cout << differentSubstring(s);
    return 0;
}