#include <bits/stdc++.h>

using namespace std;

bool isMonotonous(vector<int>inputArray){
    if(inputArray.size() == 1) return true;
    if(inputArray.size() == 2){
        if(inputArray[0] != inputArray[1])
            return true;
    }
    for(int i = 2; i < inputArray.size();i++){
        if((inputArray[i]-inputArray[i-1])*(inputArray[i-1]-inputArray[i-2]) <= 0){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    vector<int>inputArray;
    int arr;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr;
        inputArray.push_back(arr);
    }
    if(isMonotonous(inputArray)){
        cout << "TRUE";
    } else{
        cout << "FALSE";
    }
    return 0;
}