#include <bits/stdc++.h>
#pragma once 

using namespace std;

class Book{
    private: 
        string nameBook;
        string nameAuthor;
        int numberBook;
    public: 
        Book(){}
        Book(string nameBook, string nameAuthor, int numberBook)
        : nameBook(nameBook), nameAuthor(nameAuthor), numberBook(numberBook) {}
        string getNameBook() { return nameBook; }
        string getNameAuthor() { return nameAuthor; }
        int getNumberBook()  { return numberBook; }
        void display() {
            cout << "Name Book: " << nameBook << endl;
            cout << "Name Author: " << nameAuthor << endl;
            cout << "Number Book: " << numberBook << endl;
        }
};