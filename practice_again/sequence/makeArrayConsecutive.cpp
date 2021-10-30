#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int>makeArrayConsecutive(vector<int>a){
    vector<int>b;
    int k = a[0], h = 0;
    while(k != a[a.size()-1]){
        if(k == a[h]){
            h++;
            k++;
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
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int>result = makeArrayConsecutive(a);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}