//Trinh Ngoc Minh 
//6151071073
#include <bits/stdc++.h>

using namespace std;

class MyDate {
    private:
        int day;
        int month;
        int year;
    public:
        MyDate(){}
        MyDate(int day, int month, int year) : day(day), month(month), year(year) {}
        int getDay() const { return day; }
        int getMonth() const { return month; }
        int getYear() const { return year; }
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
class Person : public MyDate {
    private:
        string name;
        string address;
        string phone;
    public:
        Person(){}
        Person(string name, string address, string phone, int day, int month, int year)
        : name(name), address(address), phone(phone), MyDate(day,month,year){}
        void display(){
            cout << "Name: " << name << endl;
            cout << "Address: " << address << endl;
            cout << "Phone: " << phone << endl;
            MyDate::display();
        }
};
class Office : public Person {
    private:
        double salary;
    public:
        Office(){}
        Office(double salary, string name, string address, string phone, int day, int month, int year)
        : salary(salary), Person(name, address, phone, day, month, year){}
        void display(){
            cout << "Salary: " << salary << endl;
            Person::display();
        }
};
int main(){
    Office *source[4];
    source[0] = new Office(230000000,"Minh","Q9","0708205031",21,5,2002);
    source[1] = new Office(100000000,"Anh","Q9","0708231031",14,5,2001);
    source[2] = new Office(120000000,"An","TD","0708231031",12,1,2009);
    source[3] = new Office(150000000,"Bao","TD","0718231031",22,1,2009);
    for(int i=0; i<4; i++){
        cout << "-----------------\n";
        source[i]->display();    
    }
    for(int i=0;i<3;++i){
        for(int j=0; j<3-i;++j){
            if(source[j]->getYear() > source[j+1]->getYear()){
                swap(source[j],source[j+1]);
            } else if (source[j]->getYear() == source[j+1]->getYear()) {
                if(source[j]->getMonth() > source[j+1]->getMonth()){
                    swap(source[j],source[j+1]);
                } else if (source[j]->getMonth() > source[j+1]->getMonth()){
                    if (source[j]->getDay() > source[j+1]->getDay()){
                        swap(source[j],source[j+1]);
                    }
                }
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