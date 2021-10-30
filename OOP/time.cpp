// Tran Duc Anh
//MSSV: 6151071034
#include<bits/stdc++.h>
#define max 100
using namespace std;

class SinhVien{
    private:
        int msv;
        string name;
        int year;
        string Class;
        int  Dtb;
    public:
        friend istream& operator >>(istream &is, SinhVien &sv);
        friend ostream& operator <<(ostream& os, SinhVien sv);
        bool operator >(SinhVien sv);
        bool operator <(SinhVien sv);
        int getDtb();
};
istream& operator >> (istream &is, SinhVien &sv){
    cout<<"\nNhap ma sinh vien: ";
    is >> sv.msv;
    cin.ignore();
    cout<<"\nNhap ten sinh vien: ";
    is >> sv.name;
    cout<<"\nNhap nam sinh: ";
    is >> sv.year;
    cout<<"\nNhap lop: ";
    is >> sv.Class;
    cout<<"\nNhap diem trung binh: ";
    is >> sv.Dtb;
    return is;
}
ostream& operator<<(ostream& os, SinhVien sv){
    os<<"\nMa sinh vien: "<<sv.msv;
    os<<"\nTen sinh vien: "<<sv.name;
    os<<"\nNam sinh: "<<sv.year;
    os<<"\nLop: "<<sv.Class;
    os<<"\nDiem trung binh: "<<sv.Dtb;
    return os;
}
bool SinhVien::operator<(SinhVien sv){
    return Dtb <sv.Dtb;
}
bool SinhVien::operator>(SinhVien sv){
   return year > sv.year;
}
void sapXepGiamdanDtb(SinhVien sv[], int n){
    SinhVien temp;
    for(int i=0;i<n-1;i++){
        for(int j=i=1;j<n;j++){
            if(sv[i]<sv[j]){
                temp =sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}
void sapXepTangDanNamSinh(SinhVien sv[], int n){
    SinhVien temp;
    for(int i=0;i<n-1;i++){
        for(int j=i=1;j<n;j++){
            if(sv[i]>sv[j]){
               temp =sv[i];
               sv[i] = sv[j];
               sv[j] = temp;
            }     
        }
    }
}
int SinhVien::getDtb(){
    return Dtb;
}
void nhapDanhSach(SinhVien &sv[], int n){
    cout<<"\nNhap so luong sinh vien: "<<endl;
    cin>>n ;
    cout<<"\nNhap danh sach sinh vien!!";
    for(int i=0;i<n;i++){
        cin>>sv[i] ;
    }    
}
void xuatDanhSach(SinhVien sv[],int n){
    cout<<"\nXuat danh sach sinh vien!!"<<endl;
    for(int i=0;i<n;i++){
        cout << i+1 << "\t"; 
        cout<<sv[i] ;
    }
}
void thongKe(SinhVien sv[],int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(sv[i].getDtb() < 1){
            count++;
        }
    }
    cout<<"\nSo luong sinh vien thuoc dien canh cao hoc tap la: "<<count;
}
int main(){
    SinhVien sv[max];
    int n;
    nhapDanhSach(sv,n);
    xuatDanhSach(sv,n);
    cout<<"\nDanh sach sinh vien giam dan theo diem trung binh";
    sapXepGiamdanDtb(sv,n);
    xuatDanhSach(sv,n);
    cout<<"\nDanh sach sinh vien tang dan theo nam sinh";
    sapXepTangDanNamSinh(sv,n);
    xuatDanhSach(sv,n);
    thongKe(sv,n);
    return 0;  
}

