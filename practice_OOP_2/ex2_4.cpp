//Trinh Ngoc Minh 
//6151071073
#include <iostream>
using namespace std;
 
class Media{
    protected:
        string name;
        float cost;
    public: 
        void Input();
        void Print();
};
class Book : public Media{
    protected:
        int page;
        string artist;
    public:
        void Input();
        void Print();
};
class Video : public Media{
    protected:
        int time;
        float cost;
    public: 
        void Input();
        void Print();
};
void Media::Input(){
    fflush(stdin);
    cout <<"Name: ";
    getline (cin,name);
    cout <<"Cost: ";
    cin >> cost;
}
void Media::Print(){
    cout <<"Name: "<<name<<endl;
    cout <<"Price: "<<cost<<endl;
}
void Book::Input(){
    Media::Input();
    fflush(stdin);
    cout <<"Artist: ";
    getline (cin,artist);
    cout <<"Page: ";
    cin >> page;
}
void Book::Print(){
    Media::Print();
    cout <<"Artist: "<<artist<<endl;
    cout <<"Page: "<<page<<endl;
}
void Video::Input(){
    Media::Input();
    fflush(stdin);
    cout << "Time: ";
    cin >> time;
    cout << "Price: ";
    cin >> cost;
}
void Video::Print(){
    Media::Print();
    cout <<"Time: "<<time<<endl;
    cout <<"Price: "<<cost<<endl;
}
int main(){
    Video *vd = new Video [3];
    Book *bk = new Book [3];
    for(int i = 0; i < 3; i++) vd[i].Input();        
    for(int i = 0; i < 3; i++) vd[i].Print();
    for(int i = 0; i < 3; i++) bk[i].Input();
    for(int i = 0; i < 3; i++) bk[i].Print();
    delete vd;
    delete bk; 
    return 0;
}