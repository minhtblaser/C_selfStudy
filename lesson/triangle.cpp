#include <stdio.h>
#include<math.h>
int main(){
    int n;
    printf("enter the line of triangle: ");
    scanf("%d",&n);
    // in nua hinh tam giac 
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=i; j++){
    //         printf("*");
    //     }
    //     printf("\n");
    // }
    //in hinh tam giac hoan thien 
    // for(int i = 1; i<=n; i++){
    //     // in ky tu khoang trang
    //     for(int j = i; j<n; j++){
    //         printf(" ");
    //     }
    //     // in ky tu sao
    //     for(int j = 1; j<=(2*i-1); j++){
    //         printf("*");
    //     }
    //     printf ("\n");
    // }
    //in hinh tam giac hoan thien bi dao nguoc
    //  for(int i = 1; i <= n; i++)
    // {
    //     // in ky tu khoang trang
    //     for(int j = 1; j < i; j++)
    //     {
    //         printf(" ");
    //     }
 
    //     // in ky tu ngoi sao
    //     for(int j = 1; j <= (n*2 -(2*i-1)); j++)
    //     {
    //         printf("*");
    //     }
 
    //     // xuong dong ke tiep
    //     printf("\n");
    // }
    //IN HÌNH TAM GIÁC ĐỀU 
    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = i; j < n;j++){
    //         printf(" ");
    //     }
    //     for(int j = 1; j<=i; j++){
    //printf("* ");
    //     }
    //     printf("\n");
    // }
    //in hinh tam giac can 
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j < 2*n; j++){
    //         if((abs(n-j) <= (i-1))){
    //             printf(" * ");
    //         } else {
    //             printf("   ");
    //         }
    //     }  
    //     printf("\n");
    // }
    // in hình tam giác cân rỗng
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < 2*n-1; j++){
            if(j == n - 1 - i || j == n - 1 + i){
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
    for(int i = 0; i < 2*n-1; i++){
        printf(" * ");
    }
    return 0;
}