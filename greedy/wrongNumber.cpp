#include <bits/stdc++.h>

using namespace std;

string sum(string a, string b){
    string res = "";
    int result_number = 0, redundancy = 0;
    while(a.size()<b.size()) a = '0' + a;
    while(a.size()>b.size()) b = '0' + b;
    for(int i = a.size()-1; i >= 0; i--){
        result_number = int(a[i] - '0') + int(b[i] - '0') + redundancy;
        res  =  char(result_number%10 + '0') + res;
        redundancy /= 10;
    }
    if(redundancy > 0) return char(redundancy + '0') + res;
    return res;
}
int main(){
    string a,b;
    getline(cin,a);
    getline(cin,b);
    for(int i = 0; i < a.size(); i++){
        if(a[i] == '5'){
            a[i] = '6';
        }
        if(b[i] == '5'){
            b[i] =  '6';
        }
    }
    cout << sum(a,b) << " ";
    for(int i = 0; i < a.size(); i++){
        if(a[i] == '6'){
            a[i] = '5';
        }
        if(b[i] == '6'){
            b[i] = '5';
        }
    }
    cout << sum(a,b);
    return 0;
}