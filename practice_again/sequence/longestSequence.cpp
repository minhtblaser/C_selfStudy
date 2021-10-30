#include <bits/stdc++.h>

using namespace std;

int longestSequence(vector<int>a){
    int count = 0;
    for(int i = 0; i < a.size()-1; i++){
        int k = a[i+1] - a[i];
        for(int j = i+1; j < a.size(); j++){
            if(a[j] - a[i] == k){
                count++;
            }
        }
    }
    return count;
}
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << longestSequence(a);
    return 0;
}