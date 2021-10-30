#include<stdio.h>
int main(){
    int n;
    do{
    printf("enter n: ");
    scanf("%d",&n);
    if( n % 2 != 0){
        printf("\nplease enter odd number.");
    }
    } while ( n % 2 != 0)
    for(int i=1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(i == 1 || i == n || i == (n+1) / 2  || j == (n+1) / 2 || j == 1 || j == n){
                printf(" * "); 
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
    return 0;
}