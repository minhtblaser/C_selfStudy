#include <bits/stdc++.h>

using namespace std;

int sameCharacter(string a, string b){
    int count = 0;
    vector<int>s1(256);
    vector<int>s2(256);
    for(int i=0; i< a.length(); i++){
        s1[a[i]]++;
    }
    for(int i=0; i< b.length(); i++){
        s2[b[i]]++;
    }
    for(int i=97; i<=122; i++){
        count += min(s1[i],s2[i]);
    }
    return count;
}
int main(){
    string a,b;
    getline(std::cin,a);
    getline(std::cin,b);
    cout << sameCharacter(a,b);
    return 0;
}