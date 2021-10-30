#include <bits/stdc++.h>

using namespace std;

bool check(vector<int>inputArray){
    int k = 1, d = 1;
    for(int i = 1; i<inputArray.size();i++){
        if (inputArray[i] == inputArray[i-1]){
            k++;
        }else{
            break;
        }
    }
    inputArray.push_back(-100);
    for(int i = k+1; i<inputArray.size(); i++){
        if(inputArray[i] == inputArray[i-1]){
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
    int input;
    vector <int> inputArray;
    int n;
    cin >> n;
    while(n--){
        cin >> input;
        inputArray.push_back(input);
    }
    sort(inputArray.begin(), inputArray.end());
    if(check(inputArray)){
        cout << "TRUE";
    } else {
        cout << "FALSE";
    }
}