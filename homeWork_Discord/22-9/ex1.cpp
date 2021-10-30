#include <iostream>
#include <stack>
#include <string>

using namespace std;

string to_string(int  n){
    string s = "";
    while(n > 0){
        s =  char(n % 10 + '0') + s;
        n /= 10;
    }
    return s;
}
int main(){
    // input: aaabbc
    string s;
    //result: a3b2c1
    string str = "";
    getline(cin,s);
    //?????
    s = s + '@';
    //s.length() = 7
    //0->7
    stack<char>st;
    for(int i = 0; i<s.length(); i++){
        if(st.empty() || st.top() == s[i]) 
            {
                st.push(s[i]);
    } else {
        int count = 0; // đếm
        str = str + st.top();
        while(!st.empty())
        {
            count++;
            st.pop();
        }
        str = str + to_string(count);
        st.push(s[i]);
        }
    }
    cout << str;
    return 0;
}