#include<stdio.h>
#include<string.h>
int isWhiteSpace(char s[]);
int countWords(char s[]);
int main(){
    char s[100];
    fflush(stdin);
    printf("enter your string: ");
    gets(s);
    int result = countWords(s);
    printf("\nThe number of words in string: %d", result);
    return 0;
}
int isWhiteSpace(char c){
    return (c == ' ' || c == '\t');
}
int countWords(char s[]){
    int count = 0;
    int len = strlen(s);
    for(int i = 0; i < len-1; i++){
        if(!isWhiteSpace(s[i]) && isWhiteSpace(s[i+1]) || !isWhiteSpace(s[i]) && !isWhiteSpace(s[i+1]) && i+1 == len-1){ // i+1 == len - 1 de kt gia tri co NULL.
            
            count++;
        }
    }
    return count;
}
