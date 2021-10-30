#include <bits/stdc++.h>

using namespace std;

std::vector<string>bishopDiagonal(string bishop1, string bishop2){
    if(bishop1 > bishop2) swap(bishop1, bishop2);
    if(abs(bishop1[0] - bishop2[0]) != abs(bishop1[1] - bishop2[1])){
        return {bishop1, bishop2};
    }
    if (bishop1[1] > bishop2[1]){
        while(bishop1[0] != 'a' && bishop1[1] != '8'){
            bishop1[0]--;
            bishop1[1]++;
        }
        while(bishop2[0] != 'h' && bishop2[1] != '1'){
            bishop2[0]++;
            bishop2[1]--;
        }
        return {bishop1, bishop2};
    } else {
        while(bishop1[0] != 'a' && bishop1[1] != '1'){
            bishop1[0]--;
            bishop1[1]--; 
        }
        while(bishop2[0] != 'h' && bishop2[1] != '8'){
            bishop2[0]++;
            bishop2[1]++; 
        }
        return {bishop1, bishop2};
    }
}
int main(){
    string bishop1, bishop2;
    cin >> bishop1 >> bishop2;
    vector<string>result = bishopDiagonal(bishop1, bishop2);
    for(vector<string>::iterator it = result.begin(); it != result.end(); it++){
        cout << *it << " ";
    }
    return 0;
}