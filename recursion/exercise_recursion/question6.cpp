#include <iostream>
#include <string>  

using namespace std;


void reserveString(string a){
    if(a.size() == 0){
        return ;
    } else {
        reserveString(a.substr(1));
        cout << a[0];
    }
}
int main(){
    string a;
    getline(cin, a);
    reserveString(a);
    return 0;
}