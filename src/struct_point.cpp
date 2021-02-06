/*TODO: viết chương trình:
- nhập vào 3 điểm
- kiểm tra xem 3 điểm đó lập thành tam giác hay không?
- kiểm tra xem 3 điểm đó lập thành tam giác gì?
 */
#include<math.h>
#include<stdio.h>
typedef struct Point{
    int x;
    int y;
};
void enter_Point(Point *input);// nhập vào 1 điểm
void enter(Point *first, Point *second, Point *third);// nhập vào 3 đỉnh của tam giác
double findDistance(const Point first, const Point second);// tính khoảng cách 2 điểm
double findTrianglePerimeter(const Point first, const Point second, const Point third);// tính chu vi tam giác
double findTriangleArea(const Point first, const Point second, const Point third);// tính diện tích tam giác
bool canFormEgdeOfTriAngle(const Point first, const Point second);// 2 điểm có thể tạo thành một cạnh tam giác?
bool isPointOfTriAngle(const Point first, const Point second, const Point third);// là 3 đỉnh của tam giác?
bool isEquilateralTriangle(const Point first, const Point second, const Point third);// là tam giác đều
bool isIsoscelesTriangle(const Point first, const Point second, const Point third);// là tam giác cân
bool isRightTriangle(const Point first, const Point second, const Point third);// là tam giác vuông
bool isRightIsoscelesTriangle(const Point first, const Point second, const Point third);// là tam giác vuông cân 
void print(const Point output);// in ra 1 điểm
void print(const Point first, const Point second, const Point third);// in ra 3 điểm tam giác
void printTrianglePerimeter(const Point first, const Point second, const Point third);// in ra chu vi tam giác
void printTriangleArea(const Point first, const Point second, const Point third);// in ra diện tích tam giác
void typeOfTriangle(const Point first, const Point second, const Point third);
int main(){
    Point first, second, third;
    enter(&first, &second , &third);
    print(first, second, third);
    typeOfTriangle(first, second, third);
    printTrianglePerimeter(first, second, third);
    printTriangleArea(first, second, third);
    return 0;
}
void enter_Point(Point *input){
    printf("\nenter x: ");
    scanf("%d", &input->x);
    printf("\nenter y: ");
    scanf("%d", &input->y);
}
void enter(Point *first, Point *second, Point *third){
    printf("\nenter first point: ");
    enter_Point(first);
    printf("\nenter second point: ");
    enter_Point(second);
    printf("\nenter third point: ");
    enter_Point(third);
}
void print(const Point output){
    printf("(%d, %d)\n", output.x, output.y);
}
void print(const Point first, const Point second, const Point third){
    printf("\nPoint A: ");
    print(first);
    printf("\nPoint B: ");
    print(second);
    printf("\nPoint C: ");
    print(third);
}
double findDistance(const Point first, const Point second){
    double distance = sqrt((double)(first.x - second.x)*(first.x - second.x) + (first.y - second.y)*(first.y - second.y));
    return distance;
}
bool canFormEgdeOfTriAngle(const Point first, const Point second){
    return findDistance(first, second) != 0; // condition: unequality 0;
}
bool isPointOfTriAngle(const Point first, const Point second, const Point third){
    double AB = findDistance (first, second);
    double AC = findDistance (first, third);
    double BC = findDistance (second, third);
    return AB + AC > BC && BC + AC > AB && AB + BC > AC; // condition: the sum of 2 edge higher than the last one.
}
bool isEquilateralTriangle(const Point first, const Point second, const Point third){
    double AB = findDistance (first, second);
    double AC = findDistance (first, third);
    double BC = findDistance (second, third);
    return AB == BC && BC == AC;
}
bool isIsoscelesTriangle(const Point first, const Point second, const Point third){
    double AB = findDistance (first, second);
    double AC = findDistance (first, third);
    double BC = findDistance (second, third);
    return AB == BC || BC == AC || AB == AC;
}
bool isRightTriangle(const Point first, const Point second, const Point third){
    double AB = findDistance(first,second);
    double AC = findDistance(first,third);
    double BC = findDistance(second,third);
    return pow(AB,2)==pow(AC,2)+pow(BC,2)||pow(AC,2)==pow(AB,2)+pow(BC,2)||pow(BC,2)==pow(AB,2)+pow(AC,2);
}
bool isRightIsoscelesTriangle(const Point first, const Point second, const Point third){
    return isRightTriangle(first, second , third) && isIsoscelesTriangle(first, second, third); // condition : have both right and isosceles
}
void typeOfTriangle(const Point first, const Point second, const Point third){
    if(canFormEgdeOfTriAngle(first,second)&&canFormEgdeOfTriAngle(first,third)&&canFormEgdeOfTriAngle(second,third)&&isPointOfTriAngle(first,second,third)){
        if(isEquilateralTriangle(first,second,third)){
            printf("This is equilateral triangle\n");
        }else if(isIsoscelesTriangle(first,second,third)){
            printf("This is isosceles triangle\n");
        }else if(isRightTriangle(first,second,third)){
            printf("This is right triangle\n");
        }else if(isRightIsoscelesTriangle(first,second,third)){
            printf("This is right isosceles triangle\n");
        }else{
            printf("This is normal triangle\n");
        }
    }else{
        printf("This is not a triangle!\n");
    }
}
double findTrianglePerimeter(const Point first, const Point second, const Point third){
    double AB = findDistance (first, second);
    double AC = findDistance (first, third);
    double BC = findDistance (second, third);
    double perimeter = AB + AC + BC;
    return perimeter;
}
void printTrianglePerimeter(const Point first, const Point second, const Point third){
    double AB = findDistance(first,second);
    double AC = findDistance(first,third);
    double BC = findDistance(second,third);
    if(canFormEgdeOfTriAngle(first,second)&&canFormEgdeOfTriAngle(first,third)&&canFormEgdeOfTriAngle(second,third)&&isPointOfTriAngle(first,second,third)){
    printf("AB= %.3lf\tAC= %.3lf\tBC= %.3lf\n",AB,AC,BC);
    double triagle_perimeter = findTrianglePerimeter(first,second,third);
    printf("triangle perimeter = %.3lf\n",triagle_perimeter);
    }
}
double findTriangleArea(const Point first, const Point second, const Point third){
    double AB = findDistance(first,second);
    double AC = findDistance(first,third);
    double BC = findDistance(second,third);
    double triagle_perimeter = findTrianglePerimeter(first,second,third)/2;
    double triangle_area = sqrt(triagle_perimeter*(triagle_perimeter-AB)*(triagle_perimeter-AC)*(triagle_perimeter-BC));
    return triangle_area;
}
void printTriangleArea(const Point first, const Point second, const Point third){
    double triagle_area = findTriangleArea(first,second,third);
    printf("\ntriangle area = %.3lf\n",triagle_area);
}