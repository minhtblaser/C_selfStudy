#include<stdio.h>
#include<stdlib.h>
int main (){
    FILE *file;
    //tao file
    //mo filenhiphan
    file = fopen("thaoTacFile.txt","w");
    if(file == NULL){
        printf("\nFailed to open");
        exit(1);
    }
    //Doc hoac ghi filenhiphan
    int n;
    printf("enter the number: ");
    scanf("%d", &n);
    fprintf(file,"\nyour number %d", n);
    //dong filenhiphan
    fclose(file);
    return 0;
}