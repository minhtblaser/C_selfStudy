#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    getline(std::cin, s);
    int a[100] = {0};
    int res = 0;
    for(int i = 0; i<s.size(); i++){
        a[s[i]]++;
        if(res < a[s[i]]){
            res = a[s[i]];
        }
    }
    if(res <= s.size() -  res && s.size() % 2 == 0){
        cout << 1;
    } else if (s.size() % 2 == 1 && res <= s.size()/2 + 1){
        cout << 1;
    } else {
        cout << -1;
    }
    return 0;
}