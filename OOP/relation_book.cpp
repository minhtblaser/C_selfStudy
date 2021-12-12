#include <bits/stdc++.h>

using namespace std;

class Author {
    private:
        string name;
        string email;
    public:
        Author(){

        }
        Author(string name, string email){
            this->name = name;
            this->email = email;
        }
        void setName(string name){
            this->name = name;
        }
        string getName() const { return name; }
        void setEmail(string email){
            this->email = email;
        }
        string getEmail() const { return email; }
};
class Book : public Author {
    private:
        string name;
        vector<Author> authors;
        double price;
    public:
        Book(string name, vector<Author> authors, double price){
            this->name = name;
            this->authors = authors;
            this->price = price;
        }
        void setName(string name){
            this->name = name;
        }
        string getName() const { return name; }
        void setPrice(double price){
            this->price = price;
        }
        double getPrice()  { return price; }
        string getAuthorName(){
            string authorName = "";
            for(int i=0; i<authors.size()-1;i++){
                authorName += authors[i].getName() + ", ";
            }
            authorName += authors[authors.size()-1].getName();
            return authorName;
        }
};
int main(){
    vector<Author> authors;
    authors.push_back(Author("NgocMinh","mtblaser2002@gmail.com"));
    authors.push_back(Author("DucAnh","anhkoc@gmail.com"));
    Book book1("C++ beginners", authors, 215);
    cout << book1.getAuthorName() << endl;
    cout << book1.getPrice() << endl;
    cout << book1.getName();
    return 0;
}