#include <bits/stdc++.h>

using namespace std;

int countStamina(vector<int>a){
    int count = 1;
    int max = a[0];
    for(int i=1; i<a.size(); i++){
        max--;
        count++;
        if (max > a[i]){
            max = a[i];
        }
        if(max == 0)
            return count;
    }
    return a.size();
}
int main(){    
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    cout << countStamina(a) << endl;
    return 0;
}