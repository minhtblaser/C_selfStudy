#include<stdio.h>
#include<string.h>
void deleteEnter(char s[]);
void reserveString(char s[]);
int main(){
    char s[30];
    printf("enter your string: ");
    fgets(s,sizeof(s),stdin);
    printf("\nyour string: %s", s);
    deleteEnter(s);
    reserveString(s);
    printf("\nyour string after reserve: %s", s);
    return 0;
}
void deleteEnter(char s[]){
    size_t len = strlen(s); // int n = strlen(s);   minh = 4
    if(s[len - 1] == '\n'){
        s[len - 1] = '\0';
    }
}
void reserveString(char s[]){
    size_t len = strlen(s);
    for(int i = 0; i <len/2;i++){
        char temp = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = temp;
    }
}
