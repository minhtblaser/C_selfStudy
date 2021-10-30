#include<stdio.h>
#include<stdlib.h>
struct Author{
    char name[30];
    int year_birth;
};
struct Book {
    char id[30];
    char name[30];
    int year_published;
    Author *author; // biến chưa có lưu trong bộ nhớ.
};
void enterAuthors(Author *author);
void enterBooks(Book *book);
void printAuthors(Author *author);
void printBooks(Book *book);
void bookList(Book *book, int numberBooks);
void printBookList(Book *book, int numberBooks);
int main(){  
    Book *book;
    int numberBooks;    
    book = (Book *)calloc(1, sizeof(Book)); // create memory
    printf("\nEnter the amount of books: ");
    scanf("%d", &numberBooks);
    bookList(book, numberBooks);// input data
    printBookList(book, numberBooks);
    free(book);// free memory
    return 0;
}
void enterAuthors(Author *author){
    fflush(stdin);
    printf("name author: ");
    gets(author->name);
    printf("year_birth: ");
    scanf("%d", &author->year_birth); 
}
void printAuthors(Author *author){
    printf("\nname author: %s", author->name);
    printf("\nyear_birth: %d", author->year_birth);
}
void enterBooks(Book *book){
    printf("\nid: ");
    fflush(stdin);
    gets(book->id);
    printf("name: ");
    gets(book->name);
    printf("year_publish: ");
    scanf("%d", &book->year_published);
    printf("------------AUTHOR--------------\n");
    book->author = (Author *) calloc(1, sizeof(Author));
    enterAuthors(book->author);
}
void bookList(Book *book, int numberBooks){
    book = (Book *)realloc(book,(numberBooks)*sizeof(Book));
    for(int i=0;i<numberBooks; i++){
        printf("\nEnter book [%d]: ", i+1);
        enterBooks((book+i));
    }
}
void printBooks(Book *book){
    printf("\nid: %s", book->id);
    printf("\nname book: %s", book->name);
    printAuthors(book->author);
}
void printBookList(Book *book, int numberBooks){
    printf("-----------DATA--------------\n");
    for(int i=0;i<numberBooks;i++){
        printf("\nINFORMATION BOOK [%d]: \n", i+1);
        printBooks(&*(book+i));
    }
}

