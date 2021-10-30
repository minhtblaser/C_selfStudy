#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    getline(std::cin, s);
    int a[100] = {0};
    int res = 0,k;
    cin >> k;
    for(int i = 0; i<s.size(); i++){
        a[s[i]]++;
        if(res < a[s[i]]){
            res = a[s[i]];
        }
    }
    if((res-k) * (res-1)  <= s.size() - res){
        cout << 1;
    } else {
        cout << -1;
    }
    return 0;
}