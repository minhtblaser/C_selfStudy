#include <bits/stdc++.h>

using namespace std;

bool isArmethicSequence(vector<int>arr){
    if(arr.size() == 1) return true; 
    int k = arr[1] - arr[0];
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] - arr[i - 1] == k) return true;
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    if(isArmethicSequence(arr)){
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}