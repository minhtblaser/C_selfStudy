#include <bits/stdc++.h>

using namespace std;

bool isArithmeticProgression(vector<int>sequence){
    if(sequence.size() == 1) return true;
    int k = sequence[1] - sequence[0];
    for(int i = 1; i < sequence.size(); i++){
        if(sequence[i] - sequence[i-1] != k) return false;
    }
    return true;
}
int main(){
    vector<int>sequence;
    int n,elements;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin>>elements;
        sequence.push_back(elements);
    }
    if(isArithmeticProgression(sequence)){
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}