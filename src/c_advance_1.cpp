#include<stdio.h>
#include<time.h>
#include<math.h>
void menu(int *pa, int &n, int &position_delete, int &position_add, int &value_add);// FIXME: những biến position_delete, int position_add, int value_add có cần là tham chiếu không? 
void createRandomArray(int *pa, int &n);// NOTE: một bài ít hàm thì có thể viết tắt, nhưng mà muốn nhiều người đọc dễ hơn thì hạn chế viết tắt.
void enter(int *pa, int n);// FIXME: hạn chế viết tắt
void printValue(int *pa, int &n);
void printSquareNumbers(int *pa, int &n);
void printFristSysNumbers(int *pa, int &n);// FIXME: Frist hay first?
void printFristOddNumbers(int *pa, int &n);
void printMax(int *pa, int &n);
void printBCNN(int *pa, int &n);
void printNumberExistSmallTimes(int *pa, int &n);
void printSumOfTheOddDigit(int *pa, int n);
void printTheSumofOddNumbers(int *pa, int &n);
void deleteValue(int &position_delete, int *pa, int &n);
void deleteDigitExist2Times(int *pa, int &n);
void addValue(int &position_add, int &value_add, int *pa, int &n);   
bool checkSymmetricalNumbers(int x);// FIXME: sắp xếp những hàm có tham số truyền vào đơn giản nằm trước các hàm có tham số truyền vào phức tạp
bool checkOddNumbers(int x);
bool checkSquareNumbers(int x);
bool check_odd_Number(int x); 
int findFristOddNumbers(int *pa, int &n);
int findFristSysNumbers(int *pa, int &n);
int findMax(int *pa, int &n);
int findBCNN(int *pa, int &n);// REVIEW: full english hoặc full vietnamese
int findSumOfTheOddDigit(int *pa, int &n); 
int findSumOfOddnNumber(int *pa, int &n);
int main(){
    int a[100];
    int *pa;
    pa =  a; // create 400 byte memmory for program// FIXME: không sử dụng ntn, sử dụng cấp phát bộ nhớ, sử dụng như thế này có khác gì mảng thường đâu? Mình dùng mảng động
    int n;
    int position_delete;
    int position_add;
    int value_add;
    printf("\nenter the amount of numbers in array: ");
    scanf("%d", &n);
    printf("\n----------------------------------------");
    menu(pa,n, position_delete, position_add, value_add);
    return 0; 
}
void menu(int *pa, int &n,  int &position_delete,  int &position_add, int &value_add){
    int choice;
    do {
        printf("\n----------------------menu------------------\n");
        printf("\n0. Quit the program.");
        printf("\n1. Create a random array.");
        printf("\n2. Enter numbers in array.");
        printf("\n3. Print numbers in array.");
        printf("\n4. Find first sys_numbers in array.");
        printf("\n5. Find first odd_numbers in array.");
        printf("\n6. List square_numbers in array."); 
        printf("\n7. Find max."); 
        printf("\n8. Find BCNN."); 
        printf("\n9. Find number which have small time exist."); 
        printf("\n10. Print sum of the number have first odd digit."); 
        printf("\n11. Print sum of the odd numbers."); 
        printf("\n12. Delete one number in array."); 
        printf("\n13. Delete number exist 2 times in array."); 
        printf("\n14. Add value in array."); 
        fflush(stdin);
        printf("\nwhat is your choice? ");
        scanf("%d", &choice);
        switch (choice){
            case 0: break;
            case 1:{
                 createRandomArray(pa, n);
                 break;
            }
            case 2: {
                enter(pa, n);
                break;
            }
            case 3: {
                printValue(pa,n);
                break;
            }
            case 4: {
                printFristSysNumbers(pa, n);
                break;
            }
            case 5: {
                printFristOddNumbers(pa, n);
                break;
            }
            case 6: {
                printSquareNumbers(pa, n);
                break;
            }
            case 7: {
                printMax(pa, n);
                break;
            }
            case 8: {
                printBCNN(pa, n);
                break;
            }
            case 9: {
                printNumberExistSmallTimes(pa, n);
                break;
            }
            case 10: {
                printSumOfTheOddDigit(pa, n);
                break;
            }
            case 11: {
                printTheSumofOddNumbers(pa, n);
                break;
            }
            case 12: {
                deleteValue(position_delete, pa, n);
                break;
            }
            case 13: {
                deleteDigitExist2Times(pa, n);
                break;
            }
            case 14: {
                addValue(position_add, value_add, pa,n);
                break;
            }
            default:
                printf("\nyour choice is non-valid");
                break;
        } 
    } while (choice);
};
void createRandomArray(int *pa, int &n){
    srand((int)time(0));
    for(int i = 0; i<n; i++){
        //random from 1 to 50
        pa[i] = rand()%50 + 1;
        printf("\n number a[%d] is %d",i+1, pa[i]);
    }
}
void enter(int *pa, int n){
     for(int i = 0; i<n;i++){
        printf("\nenter a[%d]: ", i);
        scanf("%d", &pa[i]);
    }
}
void printValue(int *pa, int &n){
    printf("\n------------------------------\n");
    printf("\n the list of number: \n");
    for(int i =0; i<n;i++){
        printf("%4d", pa[i]);
    }
}
bool checkSymmetricalNumbers(int x){
    int sym_number = 0;
    int temp = x;
    while( temp != 0){
        sym_number = sym_number*10 + temp%10;
        temp /= 10;
    }
    return sym_number == x;
}
int findFristSysNumbers(int *pa, int &n){
    int first = -1;
    for(int i = 0; i<n; i++){
        bool check_sys_number = checkSymmetricalNumbers(pa[i]);
        if(check_sys_number == true){
            first = pa[i];
        }
    }
    return first;
}
void printFristSysNumbers(int *pa, int &n){
    int result_firstSys = findFristSysNumbers(pa, n);
    printf("your result: ");
    printf("%4d", result_firstSys);
}
bool checkOddNumbers(int x){
    int temp = x;
    while(temp > 9){
        temp /= 10;
    }
    if (temp % 2 == 0)
        return true;
    return false;
}
int findFristOddNumbers(int *pa, int &n){
    for(int i = 0; i<n; i++){
        bool check_odd_number = checkOddNumbers(pa[i]);
        if(check_odd_number){
            return pa[i];
        }
    }
    return -1;
}
void printFristOddNumbers(int *pa, int &n){
    int result_oddNumber = findFristOddNumbers(pa, n);
    printf("your result: ");
    printf("%4d", result_oddNumber);
}
bool checkSquareNumbers(int x){
    bool checker = false;
    int i = 0;
	while(true)    // Mặc định chạy vô tận
	{
		if(pow(2, i) == x){    // Chứng tỏ x có dạng 2^k
			checker = true;
            break;
        }
		if(pow(2, i) > x){
            checker = false;    // ĐK để thoát vòng lặp
            break;
        }
		i++;
	}
	return checker;
}
void printSquareNumbers(int *pa, int &n){
    printf("your result: ");
    for(int i = 0; i<n; i++){
        bool check_square_number = checkSquareNumbers(pa[i]);
        if(check_square_number == true){
            printf("\n%4d", pa[i]);
        }
    }
}
int findMax(int *pa, int &n){
    int max = pa[0];
    for(int i = 1; i<n; i++){
        if(pa[i]>max){
            max = pa[i];
        }
    }
    return max;
}
void printMax(int *pa, int &n){
    int result_max = findMax(pa,n);
    printf("your result: ");
    printf("%d", result_max);
}
int findBCNN(int *pa, int &n){// REVIEW: hàm này e đang làm gì vậy?
    int result_max = findMax(pa, n);
    int BCNN = result_max;
    while (true){
        bool check_BCNN = true;
        for(int i= 0; i< n; i++){
            if(BCNN % pa[i] != 0){
                check_BCNN = false;
                break;
            }
        }
        if(check_BCNN){
            return BCNN;
        }
        BCNN += result_max;
    }
}
void printBCNN(int *pa, int &n){//REVIEW: bội chung nhỏ nhất của một mảng?? @@
    int result_BCNN = findBCNN(pa, n);
    printf("your result: ");
    printf("%4d", result_BCNN);
}
int findNumberExistSmallTimes(int *pa, int &n){// REVIEW: Làm phức tạp quá
    int index[10] = {0}; // create array to count numbers exist
    for(int i =0; i<n; i++){
        int temp = abs(pa[i]);
        do{
            int b = temp % 10;
            index[b]++;
            temp /= 10;
        } while(temp > 0);
    }
    int min = 1000;
    int x_min = 0;
    for(int i = 0; i< 9; i++){
        if(index[i]>0){
            if(index[i] < min){
                min = index[i];
                x_min = i;
            }
        }
    }
    return x_min;
}
void printNumberExistSmallTimes(int *pa, int &n){
    int result_number_exist = findNumberExistSmallTimes(pa, n);
    printf("\nyour result is here %d", result_number_exist);
}
void printSumOfTheOddDigit(int *pa, int n){
    int result_sum = findSumOfTheOddDigit(pa, n);
    printf("\nyour result is here %d", result_sum);
}
int findSumOfTheOddDigit(int *pa, int &n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        bool check_the_firstODD =  checkOddNumbers(pa[i]);
        if(check_the_firstODD){
            sum += pa[i];
        }
    }
    return sum;
}
bool check_odd_Number(int x){
    if(x < 2){
        return false;// REVIEW: sử dụng biến chứa giá trị true/false
    }
    if (x > 2){
        if (x % 2 == 0){
            return false;
        } else {
            for(int i = 3; i < (int) sqrt(x); i++){
                if(x % 2 == 0){
                    return false;
                }
            }
        }
    }
    return true;
}
int findSumOfOddnNumber(int *pa, int &n){// NOTE: Tổng số chẵn = tổng - tổng số lẻ
    int sum_of_oddNumber = 0;
    for(int i = 0; i<n; i++){
        if(checkOddNumbers(pa[i])){
            sum_of_oddNumber += pa[i];
        }
    }
    return sum_of_oddNumber;
}
void printTheSumofOddNumbers(int *pa, int &n){
    int result_odd = findSumOfOddnNumber(pa, n);
    printf("\nyour result is here %d", result_odd);
}
void deleteValue(int &position_delete, int *pa, int &n){// NOTE: hàm truyền vào value, không cần nhập
// void deleteValue(int &position_delete, int *pa, int &n, int value);// với value là giá trị cần xóa
    do{
        printf("enter the position which you want to delete");
        scanf("%d", &position_delete);
    if(position_delete>n || position_delete <0)
    {
        printf("the position doesn't exist");
    }
    } while (position_delete > n || position_delete < 0);
    for(int i = position_delete; i<n-1; i++){
        pa[i] = pa[i+1];
    }
    n--; // delete memmory
}
void deleteDigitExist2Times(int *pa, int &n){
    for(int i = 0; i < n-1 ; i++){
        for(int j = i+1; j < n; i++){
            // check pa[i] exist 2 time ???
            if (  pa[i]==pa[j]){
                deleteValue(j,pa,n);// REVIEW: truyền vào hàm (pa,n,j)
                j--;
            }
        }
    }
}
void addValue(int &position_add, int &value_add, int *pa, int n){// REVIEW: truyền vào hàm (*pa,n,...);
    do{
    printf("\nenter the postion which you want to add: ");
    scanf("%d", &position_add);
    if(position_add>n || position_add <0)
    {
        printf("\nthe position doesn't exist");
    }
    }while(position_add>n || position_add<0);
    printf("\nenter new value: ");
    scanf("%d", &value_add);
    for (int i = n; i>position_add;i--){
        pa[i] = pa[i-1];
    }
    pa[position_add] = value_add;
    n++; // create new memmory
}
