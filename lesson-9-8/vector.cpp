#include <iostream>
#include <vector> 

using namespace std;
// 1) Khai báo một vector;
// 2) Tính tổng các phần tử trong vector.
// 3) tìm phần tử lớn nhất.
int main(){
    vector<int>vt;
    int n , value;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> value;
        vt.push_back(value);        
    }
    for(int i=0; i<vt.size(); i++){
        cout << vt[i] << " ";
    }
    return 0;
}