// 1. viết chương trình nhập vào 3 cạnh tam giác và tính chu vi, diện tích
// 2. viết hàm kiểm tra 3 cạnh có lập thành tam giác không?
// 3. viết hàm kiểm tra 3 cạnh lập thành tam giác gì?
// - TH1: nếu có lập thành tam giác, kiểm tra xem nó là tam giác gì?
// - TH2: nếu nó không lập thành tam giác, in ra màn hình không lập thành tam giác
//  */
#include<stdio.h>
#include<math.h>
void enter(float *first, float *second, float *third);// nhập 3 cạnh tam giác
bool isEgdeOfTriAngle(const float first, const float second, const float third);// 3 cạnh có tạo thành tam giác hay không?
bool isEquilateralTriangle(const float first, const float second, const float third);// là tam giác đều
bool isIsoscelesTriangle(const float first, const float second, const float third);// là tam giác cân
bool isRightTriangle(const float first, const float second, const float third);// là tam giác vuông
bool isRightIsoscelesTriangle(const float first, const float second, const float third);// là tam giác vuông cân 
float findTrianglePerimeter(const float first, const float second, const float third);// tìm chu vi tam giác
float findTriangleArea(const float first, const float second, const float third); // tìm diện tích tam giác
void printfTriangePerimeter(const float first, const float second, const float third);// in chu vi
void printfTriangeArea(const float first, const float second, const float third);// in ra diện tích tam giác
void checkTriagleType(const float first, const float second, const float third);// kiểm tra đó là tam giác gì?
int main(){
    float first, second, third;
    enter(&first, &second, &third);
    printfTriangePerimeter(first, second, third);
    printfTriangeArea(first, second, third);
    checkTriagleType(first, second, third);
    return 0;
}
void enter(float *first, float *second, float *third){
    do
    {
    printf("\nenter the first edge: ");
    scanf("%f", first);
    printf("\nenter the second edge: ");
    scanf("%f", second);
    printf("\nenter the first edge: ");
    scanf("%f", third);
    if(first < 0 && second < 0 && third < 0){
       printf("your edge is non-valid. Please enter again!!!");
    }
    } while(first < 0 && second < 0 && third < 0);
}
bool isEgdeOfTriAngle(const float first, const float second, const float third){
    bool check_edge1 = false;
    if(third + second > first && second + first > third && third + first > second){
        check_edge1 = true;
    }
    return check_edge1;
}
bool isEquilateralTriangle(const float first, const float second, const float third){
    bool check_edge2 = false;
    if(isEgdeOfTriAngle(first, second, third) == true){
        if(third == second && second == first){
        check_edge2 = true;
        }
    }
    return check_edge2;
}
bool isIsoscelesTriangle(const float first, const float second, const float third){
    bool check_edge3 = false; 
    if(isEgdeOfTriAngle(first, second, third) == true){
        if(third == second || second == first || first == second){
        check_edge3 = true;
        }
    }
    return check_edge3;
}
bool isRightTriangle(const float first, const float second, const float third){
    bool check_edge4 = false;
    if(isEgdeOfTriAngle(first, second, third) == true){
        if(third*third == second * second + first*first || second*second == third * third + first*first|| first*first == second * second + third*third){
        check_edge4 = true;
        }
    }
    return check_edge4;
}
float findTrianglePerimeter(const float first, const float second, const float third){
    float perimeter;
    if(isEgdeOfTriAngle(first, second, third) == true){
        perimeter = first + second + third;
    }
    return perimeter;
}
void printfTriangePerimeter(const float first, const float second, const float third){
    float result_perimeter = findTrianglePerimeter(first, second, third);
    printf("\n1. the perimeter of triangle is %.2f", result_perimeter);
}
float findTriangleArea(const float first, const float second, const float third){
   float S;
   float P = (first + second + third) / 2;
   S = sqrt(P *(P - first)* (P - second)*(P - third));
   return S;  
}
void printfTriangeArea(const float first, const float second, const float third){
    float result_area = findTriangleArea(first, third, second);
    printf("\n2. the area of triangle is %.2f", result_area);
}

void checkTriagleType(const float first, const float second, const float third){
    if(isEgdeOfTriAngle(first, second, third) == true){
        if(isEquilateralTriangle(first,second,third) == true){
            printf("\n3. this is the EquilateralTriangle ");
        } else if (isIsoscelesTriangle(first,second,third) == true) {
            printf("\n3. this is the IsoscelesTriangle ");
        } else if (isRightTriangle(first,second,third) == true){
            printf("\n3. this is the RightTriangle ");
        }
    }
}