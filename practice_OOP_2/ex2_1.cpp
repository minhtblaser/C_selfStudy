//Trinh Ngoc Minh 
//6151071073
#include <bits/stdc++.h>

using namespace std;

class MyAttr {
    private:
        int file;
    public:
        MyAttr(){}
        MyAttr(int file) : file(file) {} 
        void display(){
            cout << "File's attribute: " << file << endl;
        }
};
class MyDate {
    private:
        int day;
        int month;
        int year;
    public:
        MyDate(){}
        MyDate(int day, int month, int year) : day(day), month(month), year(year) {}
        friend bool operator >(MyDate source1, MyDate source2){
            if(source1.year > source2.year){
                return true;
            } else if (source1.year == source2.year) {
                if(source1.month > source2.month){
                    return true;
                } else if (source1.month == source2.month){
                    if (source1.day > source2.day){
                        return true;
                    }
                }
            }
            return false;
        }
        void display(){
            cout << "Date: " << day <<"/"<<month<<"/"<<year<<endl;
        }
};
class MyFile : public MyAttr, public MyDate{
    private:
        string filename;
        int filesize;
    public:
        MyFile(){}
        MyFile(int file, int day, int month, int year, string filename, int filesize) 
        : MyAttr(file), MyDate(day,month,year), filename(filename), filesize(filesize){}
        void display(){
            cout << "File name: " << filename << endl;
            cout << "File size: " << filesize << endl;
            MyAttr :: display();
            MyDate :: display();
        }
};
int main(){
    MyFile *source[4];
    source[0] = new MyFile(10,15,3,2020,"C++",2300);
    source[1] = new MyFile(15,25,5,2020,"C#",2100);
    source[2] = new MyFile(12,5,3,2020,"Java",2020);
    source[3] = new MyFile(11,11,3,2010,"Ruby",2030);
    for(int i=0; i<4; i++){
        cout << "-----------------\n";
        source[i]->display();    
    }
    for(int i=0;i<3;++i){
        for(int j=0; j<3-i;++j){
            if(source[j] > source[j+1]){
                swap(source[j], source[j+1]);
            }
        }
    }
    cout << "The list after swap: " << endl;
    for(int i=0; i<4; i++){
        cout << "-----------------" <<endl;
        source[i]->display();    
    }
    return 0;
}