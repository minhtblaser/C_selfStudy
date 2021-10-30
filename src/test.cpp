#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int>st;
    int n;
    cin >> n;
    // 13 
    while(n > 0){
        // st = {1 , 0, 1 , 1 }
        st.push(n%2);
        n /= 2;
    };
    while(!st.empty()){
        cout << st.top();
        // 1 1 0 1
        st.pop();
        //
    }
    return 0;
}