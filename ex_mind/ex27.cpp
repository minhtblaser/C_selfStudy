#include <bits/stdc++.h>

using namespace std;

int sqrt(int x){
    return x*x;
}
int checkPointCircle(vector<int>a, vector<int>b, int radius){
    int sqrt_dist = sqrt(b[0] - a[0]) + sqrt(b[1] - a[1]);
    if(sqrt_dist <= radius*radius) return 1;
    if(sqrt_dist > radius*radius) return 0;
}
int main(){
    vector <int> a;
    vector <int> b;
    int x,radius;
    cin >> radius;
    for(int i = 0; i<2; i++){
        cin >> x;
        a.push_back(x);
    }
    for(int i = 0; i<2; i++){
        cin >> x;
        b.push_back(x);
    }
    if (checkPointCircle(a,b,radius) == 1){
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}