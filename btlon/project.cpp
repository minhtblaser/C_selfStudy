#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Book {
    char id_book[30];
    char name_book[30];
    char type_book[30];
    char name_author[30];
    int year_published;
};
// void menuStudent();
//NOTE: ADMIN
void menuAdmin(Book *book, int numberBooks);
void enter(Book *book);
void enterBooks(Book *book, int numberBooks);
void printBooks(Book *book, int numberBooks);
int main(){
    Book *book;
    int numberBooks;
    book = (Book *)malloc(numberBooks * sizeof(Book));
    if(book == NULL){
        printf("\nError");
        exit(0);
    }
    printf("-----------------WELCOME TO LIBRARY-----------------");
    printf("\nAre you student or admin ?");
    int choice;
        printf("\n1. Admin.");
        printf("\n2. Student.");
        printf("\n3. Exit by click something");
        printf("\n----------------------------------------------------");
        printf("\nYour choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("\n----------------------------------------------------");
            printf("\nHello admin\nWhat do you want ?");
            menuAdmin(book, numberBooks);
        } else if (choice == 2) {
            printf("\n----------------------------------------------------");
            printf("\nHello student\nWhat do you want ?"); 
        } else {
            printf("\n----------------------------------------------------");
            printf("\nGood bye.");
        }
    free(book);
    return 0;
}
//NOTE: ADMIN
void menuAdmin(Book *book, int numberBooks){
    int choice_admin;
        do{
            printf("\n------------------------Menu--------------------\n");
            printf("1. Enter and print book\n");
            printf("2. Find books according to author.\n");
            printf("3. Arrange book according to year.\n");
            printf("4. Exit\n");
            printf("-------------------------------------------------\n");
            printf("Your choise: ");
            scanf("%d", &choice_admin);
            switch (choice_admin){
                case 1: 
                {
                    enterBooks(book, numberBooks);
                    printBooks(book, numberBooks);
                    break;
                }
            }
        } while (choice_admin != 4);
}
void enter(Book *book){
    printf("id: ");
    fflush(stdin);
    gets(book->id_book);
    printf("book's name: ");
    gets(book->name_book);
    printf("type of book: ");
    gets(book->type_book);
    printf("author's: ");
    gets(book->name_author);
    printf("year_publish: ");
    scanf("%d",&book->year_published);
}
void enterBooks(Book *book, int numberBooks){
    printf("Enter the amount of book: ");
    scanf("%d",&numberBooks);
    book = (Book *)realloc(book, numberBooks * sizeof(Book));
    for(int i = 0; i<numberBooks; i++){
        printf("\nEnter book [%d]: \n", i+1);
        enter((book+i));
    }
}
void printBooks(Book *book, int numberBooks){
    printf("------------------------DATA------------------------\n");
    printf("STT||ID\t\t||Name book\t\t||Type\t\t||Name author\t\t||Publish");
    for(int i = 0; i<numberBooks; i++){
        printf("\n00%d||%s\t\t||%s\t\t||%s\t\t||%s\t\t||%d", i+1, (book+i)->id_book, (book+i)->name_book, (book+i)->type_book, (book+i)->name_author, (book+i)->year_published);
    }
}