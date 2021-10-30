#include<stdio.h>
int main(){
    int n;
    printf("enter n: ");
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        for(int j = 1; j<=n+i-1; j++){
            if(j < n + 1 - i){
                printf("  "); 
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
    for(int i=1; i<=n; i++){
        for(int j = 1; j<=n+i-1; j++){
            if( j == n - i + 1 ||  j == n + i - 1 ||  i == n){
                printf("* "); 
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}
