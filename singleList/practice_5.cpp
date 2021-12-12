    #include <bits/stdc++.h>

    using namespace std;
    //class People
    class Person{
        public:
            string name;
            int age;
            string sex;
        public:
            friend istream& operator >>(istream&, Person&);
            Person();
            Person(string name, int age, string sex);
            ~Person(){};
            void setName(string name);
            string getName();
            void setAge(int age);
            int getAge();
            void setSex(string sex);
            string getSex();
    };
    Person::Person(){
        this->name = "";
        this->age = 0;
        this->sex = "";
    }
    Person::Person(string name, int age, string sex){
        this->name = name;
        this->age = age;
        this->sex = sex;
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
    istream& operator >>(istream&is, Person&person){
        fflush(stdin);
        cout << "Enter full name: ";
        getline(is, person.name);
        cout << "Enter your age: ";
        is >> person.age;
        fflush(stdin);
        cout << "Male or Female: ";
        getline(is, person.sex);
        return is;
    }
    //class Student
    class Student : public Person {
        private:
            string major, id;
            float GPA;
        public: 
            Student();
            Student(string major, string id, float GPA);
            ~Student(){};
            friend istream& operator >>(istream&, Student&);
            friend ostream& operator <<(ostream&, Student);
            void setMajor(string major);
            string getMajor();
            void setId(string id);
            string getId();
            void setGPA(float GPA);
            float getGPA();
    };
    Student::Student(){
        this->major = "";
        this->id = "";
        this->GPA = 0;
    }
    Student::Student(string major, string id, float GPA){
        this->major = major;
        this->id = id;
        this->GPA = GPA;
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
    istream& operator >>(istream&is, Student&student){
        // ép kiểu tường minh
        Person *p = static_cast<Person *>(&student);
        is >> *p;
        fflush(stdin);
        cout << "Enter id: ";
        getline(is, student.id);
        fflush(stdin);
        cout << "Enter major: ";
        getline(is, student.major);
        cout << "Enter GPA: ";
        is >> student.GPA;
        return is;
    }
    ostream& operator <<(ostream&os, Student student){
        os << "ID: " << student.id << endl;
        os << "Name: " << student.getName() << endl;
        os << "Age: " << student.getAge() << endl;
        os << "Sex: " << student.getSex() << endl;
        os << "Major: " << student.major << endl;
        os << "GPA: " << student.GPA << endl;
        return os;
    }
    //Single List
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
        Node *pNode = new Node(source); //create
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
        SingleList s;
        int n;
        cout << "Enter the number of student: ";
        cin >> n;
        for(int i=0; i<n; i++){
            Student data;
            cin >> data;
            s.addLast(data);
        }
        s.traverse();
        return 0;
    }