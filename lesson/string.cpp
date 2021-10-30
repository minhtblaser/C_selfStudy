#include<stdio.h>
#include<string.h>
#include<ctype.h>
void standardInput(char *string);
void delete_space(char string[30], int delete_position);
void delete_leter(char *string);
void upperCase(char *string);

int main(){
    char string[30];
    fflush(stdin);
    printf("\nenter your string: ");
    gets(string);
    standardInput(string);
    printf("\nyour string:%s", string);
    return 0;
}
void standardInput(char *string){
    delete_leter(string);
    upperCase(string);
}
void delete_space(char string[30], int delete_position){
    int n = strlen(string); // create the length of string
    for (int i = delete_position; i < n; i++)
    {
        string[i] = string[i + 1];
    }
    string[n - 1] = '\0';
}
void delete_leter(char *string){
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == ' ' && string[i + 1] == ' ')
        {
            delete_space(string, i);
            i--;
        }
        if (string[0] == ' ')
        {
            delete_space(string, 0);
        }
        if (string[strlen(string) - 1] == ' ')
        {
            delete_space(string, strlen(string) - 1);
        }
    }
}
void upperCase(char *string){
    for (int i = 0; i <= strlen(string); i++)
        {
            if (string[i] == ' ' && string[i + 1])
            string[i + 1] = toupper(string[i + 1]); 
        }
        //neu if dung thi viet hoa phan tu name[i+1]
    string[0] = toupper(string[0]);
    //luon thuc hien viet hoa phan tu name[0]
}