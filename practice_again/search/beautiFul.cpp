#include <bits/stdc++.h>

using namespace std;


bool checkBeautifulArray(vector<int>a){
    vector<int> s; 
    s.push_back(a[0]);
    for(int i = 1; i < a.size(); i++){
        s.push_back(s[i-1]+ a[i]);
    }
    for(int i = 1; i < a.size(); i++){
        if(s[i-1] == s.back() - s[i]){
            return true;
        }
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(checkBeautifulArray(a)){
        cout << "true";
    }else{
        cout << "false";
    }
    return 0;
}