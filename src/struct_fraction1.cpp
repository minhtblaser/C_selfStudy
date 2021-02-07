#include<stdio.h>
#include<math.h>
#include<string.h>
enum CompareResult{
    LARGER  = 1, EQUAL = 0, SMALLER = -1
};
typedef struct Fraction {
    int numerator, denominator;
};
int gcd(int first, int second);// ước chung lớn nhất
void enter_fraction(Fraction *first, Fraction *b); //input fration
void enter(Fraction *input);
void print(Fraction output);
void printFraction(Fraction first,Fraction second);
void printCompareResult(Fraction first, Fraction second);
Fraction compact (Fraction fraction);// rút gọn phân số
Fraction plus(Fraction first, Fraction second);// cộng hai phân số
Fraction minus(Fraction first, Fraction second);// trừ 2 phân số
Fraction multi(Fraction first, Fraction second);// nhân 2 phân số
Fraction divide(Fraction first, Fraction second);// chia 2 phân số
CompareResult compare(Fraction first, Fraction second);// so sánh 2 phân số
int main(){
    Fraction first, second, c;
    enter_fraction(&first, &second);
    printFraction(first, second);
    printf("\nThe sum of fraction 1 and fraction 2:");
    c = plus(first,second);
    print(c);
    printf("\nThe minus of fraction 1 and fraction 2: ");
    c = minus(first,second);
    print(c);
    printf("\nThe multi of fraction 1 and fraction 2: ");
    c = multi(first,second);
    print(c);
    printf("\nThe divide of fraction 1 and fraction 2: ");
    c = divide(first,second);
    print(c);
    printf("\nThe compare of fraction 1 and fraction 2 is: ");
    printCompareResult(first,second);
    return 0;
}
void enter(Fraction *input){
    printf("\nenter numerator: ");
    scanf("%d", &input->numerator);
    printf("\nenter denomirator: ");
    scanf("%d", &input->denominator);
}
void enter_fraction(Fraction *first, Fraction *second){
    printf("\nenter First fraction:");
    enter(first);
    printf("\nenter Second fraction:");
    enter(second);
}
void print(Fraction output){
    output = compact(output);
    printf("(%d / %d)\n", output.numerator, output.denominator);
}
void printFraction(Fraction first,Fraction second){
    printf("\n---------------your data------------------");
    compact(first);
    printf("\nFirst fraction: ");
    print(first);
    printf("\nSecond fraction: ");
    compact(second);
    print(second);
}
int gcd(int first, int second){
    first = abs(first);
    second = abs(second);
    while (first * second != 0){
        if(first > second){
            first %= second;
        } else {
            second %= first;
        }
    }
    return first + second;
}
Fraction compact(Fraction fraction){
    Fraction c;
    c.numerator = fraction.numerator / gcd(fraction.numerator, fraction.denominator);
    c.denominator = fraction.denominator / gcd (fraction.numerator, fraction.denominator);
    return c; 
}
Fraction plus(Fraction first, Fraction second){
    Fraction c;
    c.numerator = first.numerator*second.denominator + second.numerator*first.denominator;
    c.denominator = first.denominator * second.denominator;
    return c;
}
Fraction minus(Fraction first, Fraction second){
    Fraction c;
    c.numerator = (first.numerator * second.denominator) - (second.numerator * first.denominator);
    c.denominator = first.denominator * second.denominator;
    return c;
}
Fraction multi(Fraction first, Fraction second){
    Fraction c;
    c.numerator = first.numerator*second.numerator;
    c.denominator = first.denominator*second.denominator;
    return c;  
}
Fraction divide(Fraction first, Fraction second){
    Fraction c;
    c.numerator = first.numerator * second.denominator;
    c.denominator = first.denominator * second.numerator;
    return c;
}
CompareResult compare(Fraction first, Fraction second){
    CompareResult result = EQUAL;
    if (first.numerator * second.denominator > first.denominator * second.numerator){
        result = LARGER;
    } else if (first.numerator * second.denominator < first.denominator * second.numerator){
        result = SMALLER;
    }
    return result;
}
void printCompareResult(Fraction first, Fraction second){
    CompareResult  result = compare(first,second);
    if(result == LARGER){
        printf("fraction 1 > fraction 2");
    } else if (result == SMALLER){
        printf("fraction 1 < fraction 2");
    } else {
        printf("fraction 1 = fraction 2");
    }
}