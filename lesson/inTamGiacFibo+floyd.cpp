#include <stdio.h>
int main(){
    int n, a = 0, b = 1, c;
    int k = 1;
    printf("enter n: ");
    scanf("%d",&n);
    // for(int i = 1; i<=n; i++){
    //     a = 0;
    //     b = 1;
    //     printf("%d\t",b);
    //     for(int j = 1; j<i; j++){
    //         c = a+b;
    //         printf("%d\t", c);   
    //         a = b;
    //         b = c;
    //     }
    //     printf("\n");
    // }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            printf("%3d",k++);
        }
        printf("\n");
    }
    return 0;
}