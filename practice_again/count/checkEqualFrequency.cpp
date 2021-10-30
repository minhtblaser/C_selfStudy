#include <bits/stdc++.h>

using namespace std;

bool check(vector<int>a){
    int d = 1, k = 1;
    sort(a.begin(), a.end());
    for(int i = 1; i < a.size(); i++){
        if(a[i] == a[i-1]){
            k++;
        } else {
            break;
        }
    }
    for(int i = k + 1; i<a.size(); i++){
        if(a[i] == a[i-1]){
            d++;
        } else {
            if(d != k){
                return false;
            }
            d = 1;
        }
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    if(check){
        cout << "true";
    }else{
        cout << "false";
    }
    return 0;
}