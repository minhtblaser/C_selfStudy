#include <bits/stdc++.h>

using namespace std;

class Person{
    private:
      string name;
      int age;
      string add;
      string tel;
      string sex;
    public:
        Person(){
            
        }
        Person(string name, int age, string add, string tel, string sex){
            this->name = name;
		    this->age = age;
		    this->add = add;
		    this->tel = tel;
		    this->sex = sex;
        }
        string getName(){
            return name;
        }
        int getAge(){
            return age;
        }
        string getAdd(){
            return add;
        }
        string getTel(){
            return tel;
        }
        string getSex(){
            return sex;
        }
        virtual void display(){
            cout << "Name: " << name <<endl;
            cout << "Age: " << age <<endl;
            cout << "Sex: " << sex <<endl;
            cout << "Add: " << add <<endl;
            cout << "Tel: " << tel <<endl;
        }
        virtual long getSalary () = 0;
        static vector<Person*>findPerson(vector<Person*>p){
            vector<Person*>result;
            for(int i=0; i<p.size(); ++i){
                if(p[i]->getAdd() == "HN"){
                    result.push_back(p[i]);
                }
            }
            return result;
        }
};
class EmployeeFT: public Person{
    private:
        int day;
        long money;
    public: 
        EmployeeFT():Person(){
            
        }
        EmployeeFT(string name, int age, string add, string tel, string sex,
        int day, long money) : Person (name, age, add, tel, sex), day(day), money(money){}
        int getDay(){
            return day;
        }
        long getMoney(){
            return money;
        }
        long getSalary(){
            return (long)money*day;
        }
        virtual void display(){
            cout << "Employee Full Time" << endl;
            Person::display();
            cout << "Day: " << day << endl;
            cout << "Money: " << money << endl;
            cout << "Salary: " << getSalary() << endl;
        }
        static vector<EmployeeFT>getMaxSalary(vector<EmployeeFT>ft){
            vector<EmployeeFT>result;
            result.push_back(ft[0]);
            for(int i=1;i<ft.size();++i){
                if(result[0].getSalary()<ft[i].getSalary()){
                    result.clear();
                    result.push_back(ft[i]);
                } else if (result[0].getSalary() == ft[i].getSalary()){
                    result.push_back(ft[i]);
                }
            }
            return result;
        }
};
class EmployeePT: public Person{
    private:
        int hour;
        long money;
    public: 
        EmployeePT():Person() {
            
        }
        EmployeePT(string name, int age, string add, string tel, string sex,
        int hour, long money) : Person (name, age, add, tel, sex), hour(hour), money(money){}
        int getHour(){
            return hour;
        }
        long getMoney(){
            return money;
        }
        long getSalary(){
            return (long)money*hour;
        }
        virtual void display(){
            cout << "Employee Part Time" << endl;
            Person::display();
            cout << "Hour: " << hour << endl;
            cout << "Money: " << money << endl;
            cout << "Salary: " << getSalary() << endl;
        }
        static vector<EmployeePT>getMaxSalary(vector<EmployeePT>pt){
            vector<EmployeePT>result;
            result.push_back(pt[0]);
            for(int i=1;i<pt.size();++i){
                if(result[0].getSalary()<pt[i].getSalary()){
                    result.clear();
                    result.push_back(pt[i]);
                } else if (result[0].getSalary() == pt[i].getSalary()){
                    result.push_back(pt[i]);
                }
            }
            return result;
        }
};
int main()
{
	vector<Person*> s;
	Person* a[5];
	a[0] = new EmployeeFT("a", 18, "HN", "09842", "nam", 30, 309200);
	a[1] = new EmployeePT("b", 18, "HN", "09842", "nam", 7, 30000);
	a[2] = new EmployeeFT("c", 18, "HN", "09842", "nam", 30, 1200);
	a[3] = new EmployeePT("d", 18, "HB", "09842", "nu", 6, 1200);
	a[4] = new EmployeeFT("e", 18, "NB", "09842", "nam", 30, 130200);
	s.push_back(a[0]);  
	s.push_back(a[1]);
	s.push_back(a[2]);
	s.push_back(a[3]);
	s.push_back(a[4]);
    for(int i = 0; i <s.size(); i++){
        s[i]->display();
    }
	vector<Person*> per(Person::findPerson(s));
}