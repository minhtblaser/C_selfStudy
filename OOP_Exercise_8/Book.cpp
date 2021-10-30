#include<iostream>
#include<vector>
#include "Author.cpp"

using namespace std;

class Book {
    private:
        string name;
        double price;
        vector<Author> authors;
    public:
        Book(string name, vector<Author> authors, double price){
            this->name = name;
            this->authors = authors;
            this->price = price;
        }
        string getName()  { 
            return name;
        }
        void setName(string name){
            this->name = name;
        }
        double getPrice() {
            return price;
        }
        void setPrice(double price){
            this->price = price;
        }
        string getAuthor()  {
            string authorName = "";
            for(int i = 0; i < authors.size() - 1; i++){
                authorName += authors[i].getName() + ", ";
            }
            authorName += authors[authors.size() - 1].getName();
            return authorName;
        }
};