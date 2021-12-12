#include<bits/stdc++.h>
#include<windows.h>
//TRINH_NGOC_MINH
//6151071073
using namespace std;
// class MH is basic class
class MH{
    private:
        string tmh; //tmh: ten mat hang
        int sl; //sl: so luong
        float dg; //dg: don gia
    public:
        void nhap();
        void xuatMH();
        float tien();
        int getSL();
        float getDG();
};
// class HD inherit from class MH
// class HD is sub class
class HD : public MH{
    private:
        string thd; //thd: ten hoa don
        MH *dsmh; //dsmh: danh sach mat hang
        int slmh; //slmh: so luong mat hang
    public:
        void nhap();
        void in();
        float tongt();
        string getTHD();
};
void MH::nhap(){
    cout<<"-Nhap ten mat hang: "; 
    fflush(stdin);
    getline(cin, tmh);
    cout<<"-Nhap so luong: "; 
    fflush(stdin);
    cin>>sl;
    cout<<"-Nhap don gia: "; 
    cin>>dg;
}
void MH::xuatMH(){
    cout<<"Ten mat hang: "<<tmh<<", so luong"<<sl<<", don gia: "<<dg<<endl;
}
int MH::getSL(){
    return sl;
}
float MH::getDG(){
    return dg;
}
float MH::tien(){
    // cast type before calculate
    return (float)(sl*dg);
}
string HD::getTHD(){
    return thd;
}
void HD::nhap(){
    cout<<"+Ten hoa don: ";
    fflush(stdin);
    getline(cin, thd);
    cout<<"+So luong mat hang: "; 
    cin>>slmh;
    cout<<"+Danh sach mat hang: "<<endl;
    fflush(stdin);
    // allocate memory for pointer "dsmh"
    dsmh = new MH[slmh];
    for(int i=0; i<slmh;i++){
        cout<<"==>Mat hang "<<i+1<<endl;
        dsmh[i].nhap();
    }
}
void HD::in(){
    cout<<"-Ten hoa don: "<<thd<<endl;
    cout<<"-So luong mat hang: "<<slmh<<endl;
    cout<<"-Danh sach mat hang: "<<endl;
    for(int i=0; i<slmh;i++){
        cout<<"------------------------"<<endl;
        cout<<"===>>>Mat hang "<<i+1<<endl;
        dsmh[i].xuatMH();
    }
    cout<<"===>Tong tien: "<<tongt()<< endl;
}
float HD::tongt(){
    float tong = 0;
    for(int i=0; i<slmh;i++){
        tong += dsmh[i].tien();
    }
    return tong;
}
void inHD(HD *hd, int n){
    cout<<"-Xuat cac hoa don: "<<endl;
    for(int i=0; i<n;i++){
        cout<<"-Hoa don "<<i+1<<endl;
        hd[i].in();
    }
}
void inHDlonNhat(HD *hd, int n){
    cout<<"-Hoa don co tong tien lon nhat"<<endl;
    int max=hd[0].tongt();
    for(int i=0;i<n;i++){
        if(max<hd[i].tongt()){
            max=hd[i].tongt();
        }
    }
    for(int i=0;i<n;i++){
        if(hd[i].tongt()==max){
            hd[i].in();
        }
    }
}
void inHDnhoNhat(HD *hd, int n){
    cout<<"-Hoa don co tong tien nho nhat"<<endl;
    int min=hd[0].tongt();
    for(int i=0;i<n;i++){
        if(min>hd[i].tongt()){
            min=hd[i].tongt();
        }
    }
    for(int i=0;i<n;i++){
        if(hd[i].tongt()==min){
            hd[i].in();
        }
    }
}
void timHD(HD *hd, int n){
    string tenHD;
    cout<<"-Nhap ten hoa don can tim: ";
    fflush(stdin);
    getline(cin, tenHD);
    for(int i=0;i<n;i++){
        if(hd[i].getTHD()==tenHD){
            hd[i].in();
        }
    }
}
int main(){
    HD *hd;
    int n, luachon;
    cout<<"-Nhap so luong hoa don: ";    
    cin>>n;
    //allocate memory for pointer "hd"
    hd = new HD[n];
    for(int i=0; i<n;i++){
        cout<<"\n----------------"<<endl;
        cout<<"-Hoa don "<<i+1;
        hd[i].nhap();
    }
    do{
        system("cls");
        cout << "0.Thoat chuong trinh."<< endl;
        cout << "1.In hoa don."<<endl;
        cout << "2.Hoa don co tong tien lon nhat." << endl;
        cout << "3.Hoa don co tong tien nho nhat." << endl;
        cout << "4.Tim hoa don." << endl;
        cout << "=>Lua chon cua ban: ";
        cin >> luachon;
        switch (luachon)
        {
        case 1: 
            inHD(hd, n);
            system("pause");
            break;
        case 2: 
            inHDlonNhat(hd, n);
            system("pause");
            break;
        case 3: 
            inHDnhoNhat(hd, n);
            system("pause");
            break;
        case 4: 
            timHD(hd, n);
            system("pause");
            break;
        case 0: 
            cout <<"GOOD BYE" << endl;
            break;
        default:
            cout << "Lua chon cua ban khong hop le!!" << endl;
            break;
        }
    } while (luachon != 0);
    return 0;
}