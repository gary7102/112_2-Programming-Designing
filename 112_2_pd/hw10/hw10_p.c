#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

void simplify(int *numerator, int *denominator){
    int common = gcd(*numerator, *denominator);
    *numerator /= common;
    *denominator /= common;
}

void output(int numerator, int denominator){
    if(numerator==0) printf("0\n");
    else if(denominator == 0) printf("error\n");
    else if(numerator%denominator==0) printf("%d\n", numerator/denominator);
    else if(numerator<0 && abs(numerator) > denominator) printf("%d(%d/%d)\n", numerator/denominator, -(numerator%denominator), denominator);
    else if(numerator<0) printf("%d/%d\n", numerator, denominator);
    else if(denominator<0 && numerator > abs(denominator)) printf("%d(%d/%d)\n", numerator/denominator, numerator%(-denominator), -denominator);
    else if(denominator<0) printf("-%d/%d\n", numerator, -denominator);
    else if(numerator>denominator && denominator<0) printf("-%d(%d/%d)\n", -(numerator/denominator), numerator%(-denominator), -denominator);
    else if(numerator>denominator && numerator<0) printf("-%d(%d/%d)\n", -(numerator/denominator), (-numerator)%denominator, denominator);
    else if(numerator>denominator) printf("%d(%d/%d)\n", numerator/denominator, numerator%denominator, denominator);
    else printf("%d/%d\n", numerator, denominator);
    // printf("%d, %d\n", numerator, denominator);
}

void add(int a, int b, int c, int d){
    // printf("%d, %d, %d, %d", a, b, c, d);
    int numerator = a*d+b*c;
    int denominator = b*d;
    simplify(&numerator, &denominator);
    output(numerator, denominator);
    // printf("%d, %d\n", numerator, denominator);
}

void multiply(int a, int b, int c, int d){
    int numerator = a*c;
    int denominator = b*d;
    simplify(&numerator, &denominator);
    output(numerator, denominator);
}

void divide(int a, int b, int c, int d){
    int numerator = a*d;
    int denominator = b*c;
    simplify(&numerator, &denominator);
    output(numerator, denominator);
}

int main(){
    int numerator1, denominator1, num1;
    int numerator2, denominator2, num2;
    char fraction1[100], fraction2[100];

    scanf("%s", fraction1);
    if(strchr(fraction1, '(')){
        if(strchr(fraction1, '-')){
            sscanf(fraction1, "-%d(%d/%d)", &num1, &numerator1, &denominator1);
            numerator1 = -1*(numerator1 + denominator1*num1);
        }else{
            sscanf(fraction1, "%d(%d/%d)", &num1, &numerator1, &denominator1);
            numerator1 += denominator1*num1;
        }
    }else{
        if(strchr(fraction1, '-')){
            sscanf(fraction1, "-%d/%d", &numerator1, &denominator1);
            numerator1*=-1;
        }else{
            sscanf(fraction1, "%d/%d", &numerator1, &denominator1);
        }
    }
    // printf("numerator1=%d, denominator2=%d\n", numerator1, denominator1);
    //////////////////////////////////////
    scanf("%s", fraction2);
    if(strchr(fraction2, '(')){
        if(strchr(fraction2, '-')){
            sscanf(fraction2, "-%d(%d/%d)", &num2, &numerator2, &denominator2);
            numerator2 = -1*(numerator2 + denominator2*num2);
        }else{
            sscanf(fraction2, "%d(%d/%d)", &num2, &numerator2, &denominator2);
            numerator2 += denominator2*num2;
        }
    }else{
        if(strchr(fraction2, '-')){
            sscanf(fraction2, "-%d/%d", &numerator2, &denominator2);
            numerator2*=-1;
        }else{
            sscanf(fraction2, "%d/%d", &numerator2, &denominator2);
        }
    }
    // printf("numerator2=%d, denominator2=%d\n", numerator2, denominator2);

    add(numerator1, denominator1, numerator2, denominator2);        // a + b
    add(numerator1, denominator1, -1*numerator2, denominator2);     // a - b
    multiply(numerator1, denominator1, numerator2, denominator2);   // a * b
    divide(numerator1, denominator1, numerator2, denominator2);     // a / b
}