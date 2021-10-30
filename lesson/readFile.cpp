#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *file;
    file = fopen("Docfile.txt","r");
    if(file == NULL){
        printf("Error.");
        exit(1);
    }
    int n;
    fscanf(file,"%d",&n);
    printf("\nThe value of N is %d", n);
    fclose(file); 
    return 0;
}
