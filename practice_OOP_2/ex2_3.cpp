//Trinh Ngoc Minh 
//6151071073
#include <bits/stdc++.h>

using namespace std;


class SV {
    private:
        string class_major;
        string name;
    public:
        SV(){}
        SV(string class_major, string name) : class_major(class_major), name(name) {}
        ~SV(){}
        void display(){
            cout << "Class: " << class_major << endl;
            cout << "Name: " << name << endl;
        }
};
class SVSP : public SV {
    private: 
        float gpa;
        string schoolarship;
    public:
        SVSP(){}
        SVSP(string class_major, string name, float gpa, string schoolarship)
        : SV(class_major, name) , gpa(gpa), schoolarship(schoolarship) {}
        void display(){
            SV:: display();
            cout << "GPA: " << gpa << endl;
            cout << "Schoolarship: " << schoolarship << endl;
        } 
};
class SVCN : public SVSP {
    private: 
        float fee_study;
    public:
        SVCN(){}
        SVCN(string class_major, string name, float gpa, string schoolarship, float fee_study)
        :SVSP(class_major, name, gpa, schoolarship), fee_study(fee_study) {}
        void display(){
            SVSP:: display();
            cout << "Fee study: " << fee_study << endl;
        } 
};
int main(){
    SVCN *source[4];
    source[0] = new SVCN("IT","Minh",5.0,"YES",300000);
    source[1] = new SVCN("CAF","Fats",4.5,"YES",200000);
    source[2] = new SVCN("BUF","Anh",3.2,"YES",100000);
    source[3] = new SVCN("EMC","Mi",3.1,"NO",900000);
    for(int i=0; i<4; i++){
        cout << "-----------------\n";
        source[i]->display();    
    } 
    return 0;
}
