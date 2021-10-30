#include <bits/stdc++.h>

using namespace std;

string toString(int n){
    string s = "";
    while(n>0){
        s = char(n%10+'0') + s;
        n/=10;
    }
    return s;
}
string lineString(string s){
    string result = "";
    int k = 1;
    s = s + '@';
    for(int i=0; i<s.length()-1; i++){
        if(s[i] == s[i+1]){
            k++;
        }
        else {
            if(k>1){
                result =  result + toString(k);
            }
                result =  result + s[i];
                k = 1;
        }
    }
    return result;
}
int main(){
    string s;
    cin >> s;
    cout << lineString(s);
    return 0;
}