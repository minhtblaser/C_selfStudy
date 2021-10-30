#include <bits/stdc++.h>

using namespace std;

vector <int> makeArrayConsecutive(vector<int>a){
    vector<int>b;
    sort(a.begin(), a.end());
    int k = a[0], h = 0;
    while (k != a[a.size()-1]){
        if(k == a[h]){
            k++;
            h++;
        } else {
            while(k != a[h]){
                b.push_back(k);
                k++;
            }
        }
    }
    return b;
}
int main(){
    int n, elements;
    vector<int>a;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> elements;
        a.push_back(elements);
    }
    vector<int>result = makeArrayConsecutive(a);
    for(vector<int>::iterator it = result.begin(); it != result.end(); it++){
        cout << *it << " ";
    }
    return 0;
}