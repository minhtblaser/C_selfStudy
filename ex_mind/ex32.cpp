#include <bits/stdc++.h>

using namespace std;

bool isBeautifulArray(vector<int>a){
    vector<int>s;
    s.push_back(a[0]);
    for(int i = 1; i < a.size(); i++){
        s.push_back(s[i-1]+a[i]);
    }
    for(int i = 1; i < a.size()-1; i++){
        if(s[i] == s.back()-s[i-1])
            return true;
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if(isBeautifulArray(a)){
        cout << "true";
    }else{
        cout << "false";
    }
    return 0;
}