//Nhom 1
//Tran Duc Anh 6151071034
//Trinh Ngoc Minh 6151071073
//Nguyen Hoang Phat 6151071082
#include<bits/stdc++.h>
using namespace std;
class GiangVien{
    private:
        string id;
        string name;
        int age;
        float salary;
    public:
        virtual void input();
        virtual void output();
        virtual float calc()=0;
        float getSalary();
};
class GiangVienCoHuu:public GiangVien{
    private:
        float heSoLuong;
        int thamNien;
    public:
        void input();
        void output();
        float calc();
};
class GVTG:public GiangVien{
    private:
        int soTiet;
        float price;
    public:
        void input();
        void output();
        float calc();
};
class QLGV{
    private:
        int n;
        GiangVien *v;
    public:
        QLGV(int n);
        QLGV(QLGV &a);
        ~QLGV();
        void add();
        void display();
        void sort();
        GiangVien maxSalary();
        float sumSalary();
};
void GiangVien::input(){
    cout<<"Id: ";
    cin>>id;
    cout<<"Name: ";
    cin>>name;
    cout<<"Age: ";
    cin>>age;
    cout<<"Salary: ";
    cin>>salary;
}
void GiangVien::output(){
    cout<<"Id: "<<id<<", Name"<<name<<", Age"<<age<<",Salary"<<salary;
}
float GiangVien::getSalary(){
    return salary;
}
void GiangVienCoHuu::input(){
    cout<<"He so luong: ";
    cin>>heSoLuong;
    cout<<"Tham nien: ";
    cin>>thamNien;
}
void GiangVienCoHuu::output(){
    cout<<"He so luong: "<<heSoLuong<<", Tham nien: "<<thamNien<<endl;
}
float GiangVienCoHuu::calc(){
    return (float)((heSoLuong*1600)+(thamNien*500));
}
void GVTG::input(){
    cout<<"So tiet: ";
    cin>>soTiet;
    cout<<"Don gia: ";
    cin>>price;
}
void GVTG::output(){
    cout<<"So tiet: "<<soTiet<<", Don gia: "<<price<<endl;
}
float GVTG::calc(){
    return (float)(soTiet*price);
}
QLGV::QLGV(int n){
    this->n = n;
    v = new GiangVien[n];
}
QLGV::QLGV(QLGV &a){
    n = a.n;
    v = new GiangVien[n];
    for(int i=0;i<n;i++)    v[i]=a.v[i];
}
QLGV::~QLGV(){
    delete v;
}
void QLGV::add(){
    for(int i=0;i<n;i++){
        cout<<"Gang vien "<<i+1<<endl;
        v[i].input();
    }
}
void QLGV::display(){
    for(int i=0;i<n;i++){
        cout<<"Gang vien "<<i+1<<endl;
        v[i].output();
    }
}
void QLGV::sort(){
    GiangVien temp;
    for(int i=0;i<n-1;i++){
        for(int j = i+1; j<n;j++){
            if(v[i].getSalary()>v[j].getSalary()){
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}
GiangVien QLGV::maxSalary(){
    GiangVien max = v[0];
    for(int i = 1; i<n; i++){
        if(max<v[i].getSalary()){
            max = v[i];
        }
    }
    return max;
}
float QLGV::sumSalary(){
    float sum = 0;
    for(int i=0;i<n;i++){
        sum += v[i].getSalary();
    }
    return sum;
}
int main(){
    cout<<"Nhap so luong: ";    cin>>n;
    QLGV a(n);
    a.add();
    a.display();
    a.sort();
    (a.maxSalary()).output();
    cout<<a.sumSalary()<<endl;
}