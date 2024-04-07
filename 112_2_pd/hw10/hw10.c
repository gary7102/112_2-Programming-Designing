#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// 化簡分數
void simplify(int *numerator, int *denominator) {
    int common = gcd(*numerator, *denominator);
    *numerator /= common;
    *denominator /= common;
}

void output(int numerator, int denominator){
    // printf("%d, %d\n", numerator, denominator);
    if (numerator == 0) {
        printf("0\n");
    } else if (denominator == 0) {
        printf("error\n");
    } else if (numerator%denominator == 0) {
        printf("%d\n", numerator / denominator);
    } else if (numerator < 0) {
        printf("-%d(%d/%d)\n", -numerator / denominator, -numerator % denominator, denominator);
    } else if (denominator < 0 && (numerator<abs(denominator))) {
        printf("-%d/%d\n", numerator, -denominator);
    } else if (denominator < 0) {
        printf("-%d(%d/%d)\n", -numerator / denominator, numerator % denominator, -denominator);
    } else if ((numerator >= denominator) && (denominator<0)) {
        printf("-%d/%d\n",numerator, -1*denominator);
    } else if (numerator >= denominator) {
        printf("%d(%d/%d)\n", numerator / denominator, numerator % denominator, denominator);
    } else {
        printf("%d/%d\n", numerator, denominator);
    }
}


void add(int a, int b, int c, int d) {
    int numerator = a * d + b * c;
    int denominator = b * d;
    simplify(&numerator, &denominator);
    output(numerator, denominator);
}


int main()
{
    int a, b, c, d;

    char fraction1[100], fraction2[100];
    char op;
    int num1, num1_1, den1;

    while(1){

        scanf("%s", fraction1);
        if (strchr(fraction1, '('))
        {
            if (strchr(fraction1, '-')){
                sscanf(fraction1, "-%d(%d/%d)", &num1, &num1_1, &den1);
                num1_1 = num1_1 + (num1 * den1);
                num1_1 = num1_1 * -1;
            }else{
            sscanf(fraction1, "%d(%d/%d)", &num1, &num1_1, &den1);
            num1_1 = num1_1 + (num1 * den1);                
            }
        }else
        {
            if (strchr(fraction1, '-')){
                sscanf(fraction1, "-%d/%d", &num1_1, &den1);
                num1_1 = num1_1 * -1;
            }else{
            sscanf(fraction1, "%d/%d", &num1_1, &den1);
            }
        }
        // printf("%d/%d\n",num1_1, den1);

        scanf("%s", &op);

        int num2, num2_1, den2;
        scanf("%s", fraction2);
        if (strchr(fraction2, '('))
        {
            if (strchr(fraction2, '-')){   
                sscanf(fraction2, "-%d(%d/%d)", &num2, &num2_1, &den2);
                num2_1 = num2_1 + (num2 * den2);
                num2_1 = num2_1 * -1;
            }else{
                sscanf(fraction2, "%d(%d/%d)", &num2, &num2_1, &den2);
                num2_1 = num2_1 + (num2 * den2);
            }
        }else
        {
            if (strchr(fraction2, '-')){
                sscanf(fraction2, "-%d/%d", &num2_1, &den2);
                num2_1 = num2_1 * -1;
            }else{
                sscanf(fraction2, "%d/%d", &num2_1, &den2);
            }
        }
        // printf("%d/%d\n",num2_1, den2);
        
        a=num1_1;
        b=den1;
        c=num2_1;
        d = den2;
        // printf("%d, %d, %d, %d\n", a, b, c, d);

        if(b == 0 || d == 0){
            printf("error\n");
            // continue;
        }else{
            
            if (op == '+') {
                add(a, b, c, d);
            } else if (op == '-') {
                add(a, b, -c, d);
            } else if (op == '*') {
                int numerator = a * c;
                int denominator = b * d;
                simplify(&numerator, &denominator);
                output(numerator, denominator);
                
            } else if (op == '/') {
                if (b == 0 || d == 0) {
                    printf("error\n");
                } 
                else {
                    int numerator = a * d;
                    int denominator = b * c;
                    simplify(&numerator, &denominator);
                    output(numerator, denominator);
                }
            }
        }

        char continueOp;
        scanf(" %c", &continueOp);
        if (continueOp == 'n') {
            break;
        }
    }
    return 0;
}