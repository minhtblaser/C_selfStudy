#include <stdio.h>
main() {
   int LA[] = {1,3,5,7,8};
   int item = 10, k = 3, n = 5;
   int i = 0, j = n;
   
   printf("Danh sach phan tu trong mang ban dau:\n");
	
   for(i = 0; i<n; i++) {
      printf("LA[%d] = %d \n", i, LA[i]);
   }
    
   n = n + 1;
	
   while( j >= k){
      LA[j+1] = LA[j];
      j = j - 1;
   }
	
   LA[k] = item;
   
   printf("Danh sach phan tu cua mang sau hoat dong chen:\n");
	
   for(i = 0; i<n; i++) {
      printf("LA[%d] = %d \n", i, LA[i]);
   }
}