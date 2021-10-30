#include <bits/stdc++.h>

using namespace std;

vector<int>preFix(vector<int>arr){
    vector<int>b;
    b.push_back(arr[0]);
    for(int i=1; i<arr.size();i++){
        b.push_back(b[i-1] + arr[i]);
    }
    return b;
}
int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int>result = preFix(arr);
    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}