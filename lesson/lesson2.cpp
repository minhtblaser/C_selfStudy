#include<stdio.h>
int main(){
    int n, m;
    int temp = 0;
    printf("enter N vs M: ");
    scanf("%d %d", &n, &m);
    printf("\n--------------------");
    //ham haon doi
    temp = n;
    n = m;
    m = temp;
    printf("\nAfter:");
    printf("\ngia tri cua n:%d va m:%d", n, m);
}