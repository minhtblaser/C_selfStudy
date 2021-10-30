#include<iostream>
using namespace std;
// way 1 :
template<class T> T findMax(T a, T b){
    return (a>b) ? a:b ;
}
template<class T> void showInfo(T *arr, size_t size){
    for(size_t i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
// way 2:
template<class T> class Data {
    private:
        T *data;
        size_t size;
    public:
        Data(T *, size_t);
        void showData();
        void copyData(T*, size_t);
};
template<class T> Data <T> :: Data(T *data, size_t size){
    this->data = new T[size];
    this->size = size;
    this->copyData(data,size);
}
template<class T> void Data<T> :: showData(){
    for(size_t i = 0; i < size; i++){
        cout<< this->data[i] << " ";
    }
    cout << endl;
}
template<class T> void Data<T> :: copyData(T *data, size_t size){
    for(size_t i = 0; i < size; i++){
        this->data[i] = data[i];
    }
    cout << endl;
}
// way 3
template<class U, class V> class Pair {
    private:
        U key;
        V value;
    public: 
        Pair(U, V);
        void showPair();
};
template<class U, class V> class Pair <U, V>::Pair(U key, V value){
    this->key = key;
    this->value = value;
}
template<class U, class V> void Pair <U, V>::showPair(){
    cout << "Key: " << key << " - Value: " << value << endl;
}

class Student
{
private:
    char id[10];
    char name[100];
    int age;
    float mark;
    char address[100];
    static int count;
public:
    Student();
    // Student(char *name, char *address, char *id, int age, float mark);
    void showInfo();
    void setId(char *id);
    void setName(char *name);
    void setAddress(char *address);
    void setAge(int age);
    void setMark(float mark);
    //get information
    int getAge();
    float getMark();
    char *getName();
    char *getAddress();
    char *getId();
    static int getCount();
};
int Student::count = 0;
int Student::getCount(){
    return count;
}
Student::Student()
{ // default create
    this->name[0] = '\0';
    this->address[0] = '\0';
    this->id[0] = '\0';
    this->age = 0;
    this->mark = 0;
    count++;
}
//  Student::Student(char *name, char *address, char *id, int age, float mark)
//  {
//      cout << "\ncall 5 params constructor" << endl;
//      strcpy_s(this->name, 99, name);
//      strcpy_s(this->address, 99, address);
//      strcpy_s(this->id, 99, id);
//      this->age = age;
//      this->mark = mark;
//      count++;
//  }
void Student::showInfo()
{
    cout << "Name: " << name << endl;
    cout << "ADDRESS: " << address << endl;
    cout << "Id: " << id << endl;
    cout << "Age: " << age << endl;
    cout << "Mark: " << mark << endl;
}
int main(){
    //way 1
    // cout << findMax <int> (2,5) << endl;
    // char arr[] = {'h','e','l','l','o'};
    // int b[] = {1,2,3,4,5,6,7,8};
    // double c[] = {1.3, 1.5, 1.78};
    // showInfo<char>(arr,sizeof(arr)/sizeof(char));
    // showInfo<int>(b,sizeof(b)/sizeof(int));
    // showInfo<double>(c,sizeof(c)/sizeof(double));
    //way 2:
    // Data<char>charObj(arr, sizeof(arr)/sizeof(char));
    // Data<int>intObj(b,sizeof(b)/sizeof(int));
    // Data<double>doubleObj(c,sizeof(c)/sizeof(double));
    // charObj.showData();
    // intObj.showData();
    // doubleObj.showData();
    //Way 3
    Pair<string, int> one("One", 1);
    Pair<string, int> two("Two", 2);
    Pair<string, string> VniEng("Cat", "Con meo");
    Student student;
    Pair<string, Student> bestStudent("The best Student", student);
    return 0;
}