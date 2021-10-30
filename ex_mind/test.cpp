#include <bits/stdc++.h>
using namespace std;
class BenhNhan{
    private:
        string code; //mã bệnh nhân
        string name;
        int day; //số ngày cách ly
        string infection; //lây nhiễm từ ai
    public:
        BenhNhan(){
            this->code = "12345";
            this->name = "Meo";
            this->day = 1;
            this->infection = "23456";
        }
        BenhNhan(string code, string name, int day, string infection){
            this->code = code;
            this->name = name;
            this->day = day;
            this->infection = infection;
        }
        string getCode(){
            return code;
        }
        string getInfection(){
            return infection;
        }
        friend istream& operator>>(istream &input, BenhNhan &benhnhan){
            do{
                cout<<"Code: ";
                fflush(stdin);
                getline(cin,benhnhan.code);
            }while(benhnhan.code.size()!=5);
            cout<<"Name: ";
            fflush(stdin);
            getline(cin,benhnhan.name);
            cout<<"Day: ";
            cin>>benhnhan.day;
            do{
                cout<<"Infection: ";
                fflush(stdin);
                getline(cin,benhnhan.infection);
            }while((benhnhan.infection.size() != 5)); // SAI Điều KIỆN "NO"
        }
        void display(){
            cout<<"Code: "<<code<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Day: "<<day<<endl;
            cout<<"Infection: "<<infection<<endl;
        }
};
class BENHNHAN{
    private:
        vector<BenhNhan> list;
    public:
        BENHNHAN(){
            list = vector<BenhNhan>();
        }
        void add(BenhNhan benhnhan){
            this->list.push_back(benhnhan);
        }
        bool checkInfection(string infection){
            for(auto i = list.begin(); i != list.end(); i++){
                if(infection == i->getInfection()){
                    return true;
                    break;
                }else{
                    return false;
                }
            }
        }
};
int main(){
    BenhNhan benhnhan;
    BENHNHAN arr = BENHNHAN();
    int n; cout<<"Enter n: "; cin>>n;
    for(int i=0; i<n;i++){
        cout<<"Patient "<<i<<endl;
        do{
        cin>>benhnhan;
        arr.add(benhnhan);
        }while(arr.checkInfection(benhnhan.getInfection()));
    }
}