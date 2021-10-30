#include <bits/stdc++.h>

using namespace std;

//WAY1
// bool chessBoardCellColor(string s1, string s2){
//     if((s1[0] + s1[1] + s2[0] + s2[1]) % 2 == 0){
//         return true;
//     }
//     return false;
// }
//WAY2
int chessBoardCellColor(string s){
    int x = s[0]- 'A' + 1, y = s[1] - '0';
    return x % 2 == y % 2  ? 1:0;
}
int main(){
    string s1,s2;
    cin >> s1 >> s2;
    if(chessBoardCellColor(s1) == 1 && chessBoardCellColor(s2) == 1){
        cout << "TRUE";
    } else {
        cout << "FALSE";
    }
    return 0;
}