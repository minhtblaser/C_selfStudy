#include <bits/stdc++.h>

using namespace std;

vector <int> prefixSum(vector <int> a){
    vector <int> b;
    b.push_back(a[0]);
    for(int i = 1; i < a.size(); i++){
        b.push_back(b[i-1] + a[i]);
    }
    return b;
}
int main(){
    vector<int>a;
    int n,elements;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin>>elements;
        a.push_back(elements);
    }
    vector<int>result = prefixSum(a);
    for(vector<int>::iterator it = result.begin(); it != result.end(); it++){
        cout << *it << " ";
    }
    return 0;
}