 #include <stdio.h>
#include <sys/stat.h>
void enterByReference(int &first, int &second);
void enterByValue(int *first, int *second);
void print(const int first, const int second);
void swap (int &first, int &second);
void swap (int *first, int *second);
void printCaculate(const int first, const int second);
void printMax(const int first, const int second);
int plus(const int first, const int second);
int minus(const int first, const int second);
int multiple(const int first, const int second);
float divide(const int first, const int second);
int findMax(const int first, const int second);
bool existFile(char *path);
void exportInputValue(FILE *file, char *path, const int first, const int second);
void exportCaculatorResult(FILE *file, char *path, const int first, const int second);  
void exportMaxValue(FILE *file, char *path, const int first, const int second);
int main(){
    int first, second;
    FILE *file;
    char *path = "./data/number/inputdata.out";// *path là 1 chuỗi
    // enterByReference(first, second);
    exportInputValue(file,path,first,second);
    exportCaculatorResult(file,path,first,second);
    exportMaxValue(file,path,first,second);
    enterByValue(&first, &second);
    print(first, second);
    // swap(first, second);
    // printf("\nAfter swap by Reference {first number:%d, second number: %d}", first, second);
    swap(&first, &second);
    printf("\nAfter swap by Value {first number:%d, second number: %d}", first, second);
    printf("\n-----------------");
    printCaculate(first, second);
    printMax(first, second);

    return 0;
}
void enterByReference(int &first, int &second){
    printf("\nenter the first number: ");
    scanf("%d", &first);
    printf("\nenter the second number: ");
    scanf("%d", &second);
}
void enterByValue(int *first, int *second){
    printf("\nenter the first number (value): ");
    scanf("%d", first);
    printf("\nenter the second number(value): ");
    scanf("%d", second);
}
void print(const int first, const int second){
    printf("\n{first number:%d, second number: %d}", first, second);
}
void swap (int &first, int &second){
    int temp;
    temp = first;
    first = second;
    second = temp;
}
void swap(int *first, int *second){
    int temp;
    temp = *first;
    *first = *second;
    *second = temp;
}
int plus(const int first, const int second){
    return first + second;
}
int minus(const int first, const int second){
    return first - second;
}
int multiple(const int first, const int second){
    return first * second;
}
float divide(const int first, const int second){
    return (float)first / second;
}
void printCaculate(const int first, const int second){
    int sum = plus(first, second);
    int subtraction = minus(first, second);
    int product = multiple(first, second);
    float quotient = divide(first, second);
    printf("\n{summary: %d, substraction:%d, product:%d, quotient: %.2f}\n", sum, subtraction, product, quotient);
    printf("-----------------------------------------\n");
}
int findMax(const int first, const int second){
    return (first > second) ? first : second;
}
void printMax(const int first, const int second){
    int result_max = findMax(first, second);
    printf("\nmax is %d ", result_max);
}
void exportInputValue(FILE *file, char *path, const int first, const int second){
    const char *mode = "w";// w create a filem if file don't have any data
    file = fopen(path, mode);
    fprintf(file,"%d %d\n", first, second);
    fclose(file);
}
void cretateDefaultInputFile(FILE *file, char *path, const int first, const int second){
    const char *mode ="w";
    if(!existFile(path)){ // if file doesn't exist, program will create file 
        file = fopen(path, mode);
        fprintf(file, "%d %d\n", first, second);
        fclose(file);
    }
}
bool existFile(char *path){
    struct stat buffer;
    return !stat(path, &buffer);
}
void import (FILE *file, char *path, int &first, int &second){
    const char *mode = "r"; // reaad: reading file;
    file = fopen(path,mode);
    if(file == NULL) {
        cretateDefaultInputFile(file, path, first, second);
    } else {
        fscanf(file, "%d", &first);
        fscanf(file, "%d", &second);
    }
    fclose(file);
}
void exportMaxValue(FILE *file, char *path, const int first, const int second){
    const char *mode = "a"; // append: adding data in the end of piece 
    const int max = findMax(first, second);
    file = fopen(path, mode);
    fprintf(file, "\nmax = %d\n", max);
    fprintf(file,"\n------------------------------------\n");
    fclose(file);
}
void exportCaculatorResult(FILE *file, char *path, const int first, const int second){
    const char *mode = "a";
    int summary = plus(first, second);
    int different = minus(first, second);
    int product = multiple(first, second);
    float quotient = divide(first, second);
    file = fopen(path, mode);
    fprintf(file, "\nsummary: %d, different: %d, product: %d, quotient: %.2f", summary, different, product, quotient);
    fprintf(file,"-----------------------------------------\n");
    fclose(file);
}