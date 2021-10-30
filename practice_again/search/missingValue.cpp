#include <bits/stdc++.h>

using namespace std;

vector<int>missingValue(vector<int>a, vector<int>b){
    vector<int>check(1001);
    vector<int>ans;
    for(int i = 0; i < a.size(); i++){
        check[a[i]]++;
    }
    for(int i = 0; i < b.size(); i++){
        if(!check[b[i]]){
            ans.push_back(b[i]);
        }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    vector<int>b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    vector<int>result = missingValue(a,b);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}