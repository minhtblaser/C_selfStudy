#include <bits/stdc++.h>

using namespace std;

int commonCharacterCount(string s1, string s2){
    int a[256], b[256];
    for(int i=0; i<256; i++){
        a[i] = 0;
        b[i] = 0;
    }
    for(int i = 0; i<s1.length(); i++){
        a[s1[i]]++;
    }
    for(int i = 0; i<s2.length(); i++){
        b[s2[i]]++;
    }
    int d = 0;
    for(int i = 97; i<=122; i++){
        d+= min(a[i],b[i]);
    }
    return d;
}
int main(){
    string s1,s2;
    cin >> s1 >> s2;
    cout << commonCharacterCount(s1,s2);
    return 0;
}