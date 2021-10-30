#include <bits/stdc++.h>

using namespace std;
// Phân số a/b lớn hơn phân số c/d ⇔ (ad - bc)/bd > 0. 
// Nếu dữ kiện cho a, b, c, d > 0, thì để so sánh 2 phân số, ta chỉ cần so sánh ad - bc với 0 là được
// Ví dụ : 2/3 > 1/2, vì 2 * 2 - 3 * 1 > 0
int maxFraction(std::vector<int> numerators, std::vector<int> denominators)
{
    int cs = 0;
    for(int i = 1; i<numerators.size();i++){
        if(numerators[cs] * denominators[i]  < numerators[i] * denominators[cs]){
            // ps1 = 20
            // ps2 = 5*6;
            cs = i;
        }
    }
    return cs;
}
// 2/3 vs 1/3
int main(){
    int n;
    cin >> n;
    vector<int>numerators(n);
    vector<int>denominators(n);
    for(int i = 0; i<n; i++){
        cin >> numerators[i]; 
    }
    for(int i = 0; i<n; i++){
        cin >> denominators[i];
    }
    cout << maxFraction(numerators,denominators) <<endl;
    return 0;
}
