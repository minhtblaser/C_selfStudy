#include <iostream>

using namespace std;

class MonHoc{
	private:
		string HocPhan,TenHocPhan;
	public:
		void setHocPhan(string HocPhan);
		string getHocPhan();
		void setTenHocPhan(string TenHocPhan);
		string getTenHocPhan();
		friend istream& operator >> (istream& is, MonHoc& hp);
		friend ostream& operator << (ostream& os, MonHoc& hp);
};
void MonHoc::setHocPhan(string HocPhan){
			this->HocPhan = HocPhan;
}
string MonHoc::getHocPhan(){
			return HocPhan;
}
void MonHoc::setTenHocPhan(string TenHocPhan){
	this->TenHocPhan = TenHocPhan;
}
string MonHoc::getTenHocPhan(){
	return TenHocPhan;
}
istream& operator >> (istream& is, MonHoc& hp){
	fflush(stdin);
	cout << "Nhap hoc phan: ";
	getline(is,hp.HocPhan);
	fflush(stdin);
	cout << "Nhap ten hoc phan: ";
	getline(is,hp.TenHocPhan);
	return is;
}
ostream& operator << (ostream& os,  MonHoc& hp){
	os << hp.HocPhan << "\t" << hp.TenHocPhan;
	return os;
}

class Diem : public MonHoc{
	protected:
		float DiemQuaTrinh,DiemThi,DiemTong;
	public:
		void NhapDiem();
		void XuatDiem(Diem b);
};
void Diem::NhapDiem(){
	Diem b;
	MonHoc *a = static_cast <MonHoc *> (&b);
	cin >> *a;
	cout << "Nhap diem qua trinh: ";
	cin >> DiemQuaTrinh;
	cout << "Nhap diem thi: ";
	cin >> DiemThi;
	cout << "Nhap Diem Tong: ";
	cin >> DiemTong;
}
void Diem::XuatDiem(){
	cout << b.getHocPhan() << "\t" << b.getTenHocPhan() << "\t" << DiemQuaTrinh << "\t" << DiemThi << "\t" << DiemTong << "\t";
} 
int main(){
 	Diem a;
 	a.NhapDiem();
	a.XuatDiem();
	return 0;
}