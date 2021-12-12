#include <bits/stdc++.h>
#pragma once
//Ho ten: Trinh Ngoc Minh 
//MSSV: 6151071073
//Ngay sinh: 21/05/2002
//Email: 6151071073@st.utc2.edu.vn
using namespace std;

class Language {
    private:
        string english;
        string vietnamese;
    public:
        Language(){}
        Language(string english,string vietnamese) : english(english), vietnamese(vietnamese){}
        string getEnglish() const { return english;}
        void setEnglish(string english){ this->english = english;}
        string getVietnamese() const { return vietnamese;}
        void setVietnamese(string vietnamese){this->vietnamese = vietnamese;}
        ~Language(){}
        friend istream& operator >>(istream&, Language&);
        friend ostream& operator <<(ostream&, Language);
};
istream& operator >>(istream&is, Language&source){
    is>>std::ws;
    getline(is,source.english);
    is>>std::ws;
    getline(is,source.vietnamese);
    return is;
}
ostream& operator <<(ostream&os, Language source){
    os << source.english <<": " << source.vietnamese << endl;
    return os;
}