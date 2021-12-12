#include <iostream>
#include <fstream>
using namespace std;

class Person{
	private:
		string name;
		int age;
		string sex;
	public:
		friend istream& operator >> (istream& is, Person& ps);
		Person();
		Person(string name, int age, string sex);
		~Person();
		void setName(string name);
		string getName();
		void setAge(int age);
		int getAge();
		void setSex(string sex);
		string getSex();
};
Person::Person(){
	name = "";
	age = 0;
	sex = "";
}
Person::Person(string name, int age, string sex){
	this->name = name;
	this->age = age;
	this->sex = sex;
}
Person::~Person(){
}
void Person::setName(string name){
	this->name = name;
}
string Person::getName(){
	return name;
}
void Person::setAge(int age){
	this->age = age;
}
int Person::getAge(){
	return age;
}
void Person::setSex(string sex){
	this->sex = sex;
}
string Person::getSex(){
	return sex;
}
istream& operator >> (istream& is, Person& ps){
	char na[40], ad[40], ph[20];
	is.getline(na, 40);
	is >> ps.age;
	fflush(stdin);
	getline(is, ps.sex);
}

class Student : public Person{
	private:
		string major, id;
		float GPA;
	public:
		Student();
		Student(string major, string id, float GPA);
		~Student();
		friend istream& operator >> (istream& is, Student& st);
		friend ostream& operator << (ostream& os, Student& st);
		void setMajor(string major);
		string getMajor();
		void setId(string id);
		string getId();
		void setGPA(float GPA);
		float getGPA();
};
Student::Student(){
	major = "";
	id = "";
	GPA = 0;
}
Student::Student(string major, string id, float GPA){
	this->major = major;
	this->id = id;
	this->GPA = GPA;
}
Student::~Student(){

}
void Student::setMajor(string major){
	this->major = major;
}
string Student::getMajor(){
	return major;
}
void Student::setId(string id){
	this->id = id;
}
string Student::getId(){
	return id;
}
void Student::setGPA(float GPA){
	this->GPA = GPA;
}
float Student::getGPA(){
	return GPA;
}
istream& operator >> (istream& is, Student& st){
	Person *a = static_cast <Person *> (&st);
	fflush(stdin);
	is >> *a;
	cout << "Enter major: ";
	getline(is, st.major);
	cout << "Enter id: ";
	getline(is, st.id);
	cout << "Enter GPA: ";
	is >> st.GPA;
	return is;
}


ostream& operator << (ostream& os, Student& st){
	os << st.getName() << endl;
	os << st.getAge() << endl;
	os  << st.getSex() << endl ;
	os  << st.major << endl;
	os << st.id << endl;
	os << st.GPA << endl; 
	return os;
}
class Node {
        public:
            Student data;
            Node *pNext;
            Node(Student data){
                this->data = data;
                pNext = NULL;
            }
    };
class SingleList {
        private:
            Node *pHead;
            Node *pTail;
            int size;
        public:
            SingleList(){
                pHead = NULL;
                pTail = NULL;
                size = 0;
            }
            ~SingleList(){};
            void addLast(Student source);
            Node *getHead();
            Node *getTail();                
            void traverse();
    };
Node* SingleList::getHead(){
        return pHead;
    }
Node* SingleList::getTail(){
        return pTail;
    }
void SingleList::addLast(Student source){
        Node *pNode = new Node(source);
        if(size == 0){
            pHead = pTail = pNode;
        } else {
            pTail->pNext = pNode;
            pTail = pNode;
        }
        size++;
    }     
void SingleList::traverse(){
        Node *temp = pHead;
        while(temp != NULL){
            cout << temp->data;
            temp = temp->pNext;
        }
}
int main(){
    	ifstream file;
    	file.open("text.txt");
        SingleList s;
		int n;
		file >> n;
		for(int i = 0; i < n; i++){
			Student data;
			file >> data;
			s.addLast(data);
		}
        s.traverse();
        file.close();
        return 0;
    }