#include<stdio.h>
#include<string.h>
#include<ctype.h>
void countLetterA(char *s);
void countLetter(char *s);
int main(){
    char s[100];
    fflush(stdin);
    printf("enter your string:");
    gets(s);
    printf("\nThe number of occurences (distinguish A >< a): ");
    countLetterA(s);
    printf("\nThe number of occurences: ");
    countLetter(s);
    return 0;
}
void countLetterA(char *s){
    int len = strlen(s);
    int b[97+26] = {0};
    for (int i = 0; i<len; i++){
        b[s[i]]++; // nếu gặp từ đó thì sẽ tăng lên một chữ số.
    }
    for(int i = 97; i < 123; i++){
        printf("\n%c: %d", (char)i, b[i]);
    }
    for(int i = 65; i < 91; i++){
        printf("\n%c: %d", (char)i, b[i]);
    }
}
void countLetter(char *s){
    int len =  strlen(s);
    int b[97 + 26] = {0};
    for(int i = 0; i < len; i++){
        //bien tat ca chu thanh chu dang thuong 
        s[i] = tolower(s[i]);
        b[s[i]]++; 
        // s[i] se bien thanh ma so ASCII => bien thanh phan tu so
        // ki tu cua ma tuong ung xuat hien mot lan 
    }
    for(int i = 97; i <  123; i++){
        printf("\n%c: %d", (char)i, b[i]);
    }
}