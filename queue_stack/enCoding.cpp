#include <bits/stdc++.h>

using namespace std;

string to_String(int n){
    string result = "";
    while (n>0){
        result = char(n%10 + '0') + result;
        n /= 10;
    }
    return result;
}
int main(){
    string s;
    getline(std::cin, s);
    stack<char>st;
    string result = "";
    s = s + '@';
    for(int i = 0; i < s.size(); i++){
        if(st.empty() || st.top() == s[i]){
            st.push(s[i]);
        } else {
            int count = 0;
            result = result + st.top();
            while(!st.empty()){
                count++;
                st.pop();
            }
            result = result + to_String(count);
            st.push(s[i]);
        }
    }
    cout << result << endl;
    return 0;
}