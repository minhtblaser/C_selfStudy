#include<stdio.h>
// in hinh chu nhat
int main(){
    int n,m;
    printf("Nhap chieu dai:");
    scanf("%d", &n);
    printf("\nNhap chieu rong:");
    scanf("%d", &m);
    printf("\n");
    // in hinh chu nhat binh thuong
//     for(int i=0; i<m; i++){
//         for(int j = 0; j<n; j++){
//             printf("*");
//         }
//         printf("\n");
//     }
    //in hinh chu nhat rong
    for(int i=0; i<=m; i++){
        for(int j = 0; j<=n;j++){
            if(i == 0|| j == 0|| i == m || j ==n){
            printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
