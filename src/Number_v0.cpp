#include <stdio.h>
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
int main(){
    int first, second;
    enterByReference(first, second);
    // enterByValue(&first, &second);
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
}//:P :P :P :P
if (){
    
}