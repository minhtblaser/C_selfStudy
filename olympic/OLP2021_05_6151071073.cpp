//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
#include<bits/stdc++.h>
using namespace std;
 
int main(){ 
    ifstream in("OLP2021_05.INP");
    ofstream out("OLP2021_05.OUT");
    int m,n,k;
    in>>m>>n>>k;
    int S=(m+n)-k;
    if(m>=n) out<<S/3;
    else out<<(S/3)-1;
    return 0;
}