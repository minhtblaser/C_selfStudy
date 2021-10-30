#include "Author.cpp"
#include "Book.cpp"

int main(){
    vector<Author> authors;
    authors.push_back(Author("Minh","Minh@gmail"));
    authors.push_back(Author("Ngoc","Minh@gmail"));
    authors.push_back(Author("Trinh","Minh@gmail"));

    Book book1 ("C++ FOR BEGINNERS", authors, 21000000);
    cout << book1.getAuthor() << endl;
    return 0;
}