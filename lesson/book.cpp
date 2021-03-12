#include<stdio.h>
#include<stdlib.h>
struct Author{
    char id[30];
    char name[30];
    int year_birth;
};
struct Book {
    char id[30];
    char name[30];
    Author *author; // biến chưa có lưu trong bộ nhớ.
};
void enter(Author *author);
void print(Author *author);
int main(){  
    Author *author;
    author = (Author *)calloc(1, sizeof(Author)); // create mem
    enter(author);// input data
    print(author);// ouput data
    free(author);// free memory
    return 0;
}
void enter(Author *author){
    printf("id: ");
    fflush(stdin);
    gets(author->id);
    printf("name: ");
    gets(author->name);
    printf("year_birth: ");
    scanf("%d", &author->year_birth); 
}
void print(Author *author){
    printf("\nid: %s", author->id);
    printf("\nname: %s", author->name);
    printf("\nyear_birth: %d", author->year_birth);
}
