#include<stdio.h>
#include<math.h>
// void exportCaculatorResult(FILE *file, char *path, const int first_degree,int first_coefficient[],const int second_degree, int second_coefficient[], const int result_degree, int result_coefficient[], float result_coefficient_div[]);
void enterPolynimal(int coefficient[], int &degree);
float getValue(const int coefficient[],const int degree,float x);
void sumPolynomial( int first_coefficient[],const int first_degree, int second_coefficient[], const int second_degree, int result_coefficient[], int &result_degree);
void printPolynimal( int coefficient[],const int degree);
void minusPolynomial(  int first_coefficient[],const int first_degree, int second_coefficient[], const int second_degree, int result_coefficient[], int &result_degree);
void mulPolynomial(  int first_coefficient[],const int first_degree, int second_coefficient[], const int second_degree, int result_coefficient[], int &result_degree);
void divPolynomial(  int first_coefficient[],const int first_degree, int second_coefficient[], const int second_degree, float result_coefficient_div[], int &result_degree);
void print_divide(float result_coefficient_div[],const int degree);
int getDerivative(const int first_coefficient[],const int first_degree,const int value);
int main(){
    const int MAX = 100;
    FILE *file;
    char *path = "./data/number/inputdata.out";
    int value = 3;
    int first_coefficient[MAX],second_coefficient[MAX],result_coefficient[MAX];
    float result_coefficient_div[MAX];
    int first_degree,second_degree, result_degree;
    printf("--------first polynimal--------\n");
    enterPolynimal(first_coefficient,first_degree);
    printf("- The first polynomial: ");
    printPolynimal(first_coefficient,first_degree);
    // get derivatie with x = 3;
    int result_derivatie = getDerivative(first_coefficient,first_degree,value);
    printf("\n- Get derivatie: ");
    printf("\nThe value of X = %d at first derivatie of first polynomial is %d",value, result_derivatie);
    // get value of 1 with x = 3;
    printf("\nx = 3=> value of first polynimal:%.2f",getValue(first_coefficient,first_degree,3));
    // the second polynimal
    printf("\n--------second polynimal--------\n");
    enterPolynimal(second_coefficient,second_degree);
    printf("- The second polynomial: ");
    printPolynimal(second_coefficient,second_degree);
    //caculator
    printf("\n--------The caculator of 2 polynimal--------");
    //sum
    printf("\n- The sum of 2 polynimal: ");
    sumPolynomial(first_coefficient,first_degree,second_coefficient,second_degree,result_coefficient,result_degree);
    printPolynimal(result_coefficient,result_degree);
    //minus
    printf("\n- The minus of 2 polynimal: ");
    minusPolynomial(first_coefficient,first_degree,second_coefficient,second_degree,result_coefficient,result_degree);
    printPolynimal(result_coefficient,result_degree);
    //multiply
    printf("\n- The multiply of 2 polynimal: ");
    mulPolynomial(first_coefficient,first_degree,second_coefficient,second_degree,result_coefficient,result_degree);
    printPolynimal(result_coefficient,result_degree);
    //divide
    printf("\n- The divide of 2 polynimal: ");
    divPolynomial(first_coefficient,first_degree,second_coefficient,second_degree,result_coefficient_div,result_degree);
    print_divide(result_coefficient_div,result_degree);
    return 0;
}
void enterPolynimal(int coefficient[], int &degree){
    do{
        printf("- Enter degree of polynimal: ");
        scanf("%d",&degree);
    }while(degree<0);
    for(int i=0; i<=degree; i++){
        printf("confficient[%d] = ",i);
        scanf("%d",&*(coefficient+i));
    }   
}
float getValue(const int coefficient[],const int degree,float x){
    int result = 0;
    for(int index=0; index<=degree; index++){
        result+=coefficient[index]*pow(x,index); 
    }
    return result;
}
void sumPolynomial(  int first_coefficient[],const int first_degree, int second_coefficient[], const int second_degree, int result_coefficient[], int &result_degree){// hàm này kiểu void
    // TODO: tổng 2 đa thức cùng bậc, kết quả bỏ vào result
    if(first_degree==second_degree){
        result_degree = first_degree;
        for(int index = 0; index <= result_degree;index++){
            result_coefficient[index] = first_coefficient[index] + second_coefficient[index];
        }
    }
    // TODO: tổng 2 đa thức khác bậc, kết quả bỏ vào result. 
    else if(first_degree>second_degree){//test sai
        result_degree = first_degree;
        for(int index = 0; index<=second_degree; index++){
            result_coefficient[index] = first_coefficient[index] + second_coefficient[index];// lưu phép tính cộng
        }
        for(int index=second_degree+1; index<=first_degree;index++){// nó k chạy vô đây
            result_coefficient[index]= first_coefficient[index];
        }
    }
    else{
        result_degree = second_degree;
        for(int index = 0; index<=second_degree; index++){
            result_coefficient[index] = first_coefficient[index] + second_coefficient[index];
        }
        for(int index=first_degree+1; index<=second_degree;index++){
            result_coefficient[index]= second_coefficient[index];
        }
    }
}
void minusPolynomial(  int first_coefficient[],const int first_degree, int second_coefficient[], const int second_degree, int result_coefficient[], int &result_degree){
    // TODO: tổng 2 đa thức cùng bậc, kết quả bỏ vào result
    if(first_degree==second_degree){
        result_degree = first_degree;
        for(int index = 0; index <= result_degree;index++){
            result_coefficient[index] = first_coefficient[index] - second_coefficient[index];
        }
    }
    // TODO: tổng 2 đa thức khác bậc, kết quả bỏ vào result. 
    else if(first_degree>second_degree){//test sai
        result_degree = first_degree;
        for(int index = 0; index<=second_degree; index++){
            result_coefficient[index] = first_coefficient[index] - second_coefficient[index];
        }
        for(int index=second_degree+1; index<=first_degree;index++){
            result_coefficient[index]= first_coefficient[index];
        }
    }
    else{
        result_degree = second_degree;
        for(int index = 0; index<=second_degree; index++){
            result_coefficient[index] = first_coefficient[index] - second_coefficient[index];
        }
        for(int index=first_degree+1; index<=second_degree;index++){
            result_coefficient[index]= second_coefficient[index];
        }
    }
}
void mulPolynomial(  int first_coefficient[],const int first_degree, int second_coefficient[], const int second_degree, int result_coefficient[], int &result_degree){
    // TODO: tổng 2 đa thức cùng bậc, kết quả bỏ vào result
    if(first_degree==second_degree){
        result_degree = first_degree;
        for(int index = 0; index <= result_degree;index++){
            result_coefficient[index] = first_coefficient[index] * second_coefficient[index];
        }
    }
    // TODO: tổng 2 đa thức khác bậc, kết quả bỏ vào result. 
    else if(first_degree>second_degree){
        result_degree = first_degree;
        for(int index = 0; index<=second_degree; index++){
            result_coefficient[index] = first_coefficient[index] * second_coefficient[index];
        }
        for(int index=second_degree+1; index<=first_degree;index++){
            result_coefficient[index]= first_coefficient[index];
        }
    }
    else{
        result_degree = second_degree;
        for(int index = 0; index<=second_degree; index++){
            result_coefficient[index] = first_coefficient[index] * second_coefficient[index];
        }
        for(int index=first_degree+1; index<=second_degree;index++){
            result_coefficient[index]= second_coefficient[index];
        }
    }
}
void divPolynomial(  int first_coefficient[],const int first_degree, int second_coefficient[], const int second_degree,  float result_coefficient_div[], int &result_degree){
    // TODO: tổng 2 đa thức cùng bậc, kết quả bỏ vào result
    if(first_degree==second_degree){
        result_degree = first_degree;
        for(int index = 0; index <= result_degree;index++){
            result_coefficient_div[index] = (float)first_coefficient[index] / second_coefficient[index];
        }
    }
    // TODO: tổng 2 đa thức khác bậc, kết quả bỏ vào result. 
    else if(first_degree>second_degree){//test sai
        result_degree = first_degree;
        for(int index = 0; index<=second_degree; index++){
            result_coefficient_div[index] = (float) first_coefficient[index] / second_coefficient[index];
        }
        for(int index=second_degree+1; index<=first_degree;index++){
            result_coefficient_div[index]= first_coefficient[index];
        }
    }
    else{
        result_degree = second_degree;
        for(int index = 0; index<=second_degree; index++){
            result_coefficient_div[index] = (float)first_coefficient[index] / second_coefficient[index];
        }
        for(int index=first_degree+1; index<=second_degree;index++){
            result_coefficient_div[index]= second_coefficient[index];
        }
    }
}
void print_divide( float result_coefficient_div[],const int degree){
    for(int index=degree; index>0; index--){
        if(result_coefficient_div[index] == 0){
            continue;
        }
        else if(result_coefficient_div[index]==1){
            printf("x^%d",index);
        }
        else{    
            printf("%.2f*x^%d",result_coefficient_div[index],index);
        }
            printf("+");
    }
    printf("%.2f",result_coefficient_div[0]);
}
void printPolynimal(int coefficient[],const int degree){
    for(int index=degree; index>0; index--){
        if(coefficient[index] == 0){
            continue;
        }
        else if(coefficient[index]==1){
            printf("x^%d",index);
        }
        else{    
            printf("%d*x^%d",coefficient[index],index);
        }
            printf("+");
    }
    printf("%d",coefficient[0]);
}
int getDerivative(const int coefficient[],const int degree,const int value){
    int result = 0;
    for(int i = 0;i<=degree;i++){
        result += coefficient[i]*pow(value,i);
    }
    return result;
}
// void exportCaculatorResult(FILE *file, char *path, const int first_degree,int first_coefficient[],const int second_degree, int second_coefficient[],  int &result_degree, int result_coefficient[], float result_coefficient_div[]){
//     const char *mode = "a";
//     file = fopen(path, mode);
//     fprintf(file,"- The sum of 2 polynimal:", sumPolynomial(first_coefficient,first_degree,second_coefficient,second_degree,result_coefficient, result_degree));// truyền zô 1 giá trị kiểu void @@ end, lag that anh @@
//     for(int index=result_degree; index>0; index--){
//         if(result_coefficient[index] == 0){
//             continue;
//         }
//         else if(result_coefficient[index]==1){
//             fprintf(file,"x^%d",index);
//         }
//         else{    
//             fprintf(file,"%d*x^%d",result_coefficient[index],index);
//         }
//             fprintf(file,"+");
//     }
//     fprintf(file,"%d",result_coefficient[0]);
//     fclose(file);
// }
//1) in ra file 
//2) chia hàm ra để quản lý