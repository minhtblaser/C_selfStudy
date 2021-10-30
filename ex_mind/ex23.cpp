#include <bits/stdc++.h>

using namespace std;

bool bishopAndPawn(string s1, string s2){
    return (abs(s1[0] - s2[0]) == abs(s1[1] - s2[1]) && s1[0] - s2[0] != 0);
}
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    if(bishopAndPawn(s1, s2)){
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}