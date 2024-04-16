/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int gcd(int a, int b){return (b==0)? a : gcd(b, a%b);}

void simplify(int *numerator, int *denominator){
    int common = gcd(*numerator, *denominator);
    *numerator /= common;
    *denominator /= common;
}

void output(int numerator, int denominator){
    if(numerator==0) printf("0\n");
    // else if(numerator%denominator == 0 && (numerator<0 || denominator<0)) printf("-%d", )
    else if(numerator%denominator == 0) printf("%d\n", numerator/denominator);
    else if(numerator<0 && abs(numerator) > denominator) printf("-%d(%d/%d)\n", (-numerator)/denominator, (-numerator)%denominator, denominator);
    else if(numerator<0) printf("-%d/%d\n", -(numerator), denominator);
    else if(denominator<0 && numerator > abs(denominator)) printf("-%d(%d/%d)\n", numerator/(-denominator), numerator%(-denominator), -denominator);
    else if(denominator<0) printf("-%d/%d\n", numerator, (-denominator));
    else if(numerator>denominator) printf("%d(%d/%d)\n", numerator/denominator, numerator%denominator, denominator);
    else printf("%d/%d\n", numerator, denominator);
}

int check_devide_by_zero(int denominator){
    if(denominator==0){printf("error\n"); return 1;}
    return 0;
}

void add(int a, int b, int c, int d){
    int numerator = a*d+b*c;
    int denominator = b*d;
    simplify(&numerator, &denominator);
    output(numerator, denominator);
    // printf("%d %d\n", numerator, denominator);
    
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
    if(check_devide_by_zero(denominator)) return;
    simplify(&numerator, &denominator);
    output(numerator, denominator);
}



int main(){
    char fraction1[50], fraction2[50];
    int numerator1, denominator1;
    int numerator2, denominator2;
    scanf("%s", fraction1);
    if(strchr(fraction1, '(')){
        int num1;
        if(strchr(fraction1, '-')){
            sscanf(fraction1, "-%d(%d/%d)", &num1, &numerator1, &denominator1);
            numerator1 = -1*(numerator1+num1*denominator1);
        }else{
            sscanf(fraction1, "%d(%d/%d)", &num1, &numerator1, &denominator1);
            numerator1 = numerator1+num1*denominator1;
        }
    }else{
        if(strchr(fraction1, '-')){
            sscanf(fraction1, "-%d/%d", &numerator1, &denominator1);
            numerator1 *= -1;
        }else{
            sscanf(fraction1, "%d/%d", &numerator1, &denominator1);
        }
    }

    scanf("%s", fraction2);
    if(strchr(fraction2, '(')){
        int num2;
        if(strchr(fraction2, '-')){
            sscanf(fraction2, "-%d(%d/%d)", &num2, &numerator2, &denominator2);
            numerator2 = -1*(numerator2+num2*denominator2);
        }else{
            sscanf(fraction2, "%d(%d/%d)", &num2, &numerator2, &denominator2);
            numerator2 = numerator2+num2*denominator2;
        }
    }else{
        if(strchr(fraction2, '-')){
            sscanf(fraction2, "-%d/%d", &numerator2, &denominator2);
            numerator2 *= -1;
        }else{
            sscanf(fraction2, "%d/%d", &numerator2, &denominator2);
        }
    }

    if(check_devide_by_zero(denominator1)) return 0;
    if(check_devide_by_zero(denominator2)) return 0;
    // printf("13\n");
    add(numerator1, denominator1, numerator2, denominator2);
    add(numerator1, denominator1, -1*numerator2, denominator2);
    multiply(numerator1, denominator1, numerator2, denominator2);
    divide(numerator1, denominator1, numerator2, denominator2);
    // printf("%d, %d\n", numerator1, denominator1);
    // printf("%d, %d\n", numerator2, denominator2);
}
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void output(int numerator, int denominator){
    // printf("numerator = %d, denominator = %d\n", numerator, denominator);
    if(numerator==0) printf("0\n");
    else if(numerator%denominator==0) printf("%d\n", numerator/denominator);
    else if(numerator<0 && abs(numerator) > denominator) printf("%d(%d/%d)\n", numerator/denominator, (-numerator)%denominator, denominator);
    else if(numerator<0) printf("%d/%d\n", numerator, denominator);
    else if(denominator<0 && numerator > abs(denominator)) printf("%d(%d/%d)\n", numerator/denominator, numerator%(-denominator), -denominator);
    else if(denominator<0) printf("%d/%d\n", -numerator, -denominator);
    else if(numerator > denominator) printf("%d(%d/%d)\n", numerator/denominator, numerator%denominator, denominator);
    else printf("%d/%d\n", numerator, denominator);
}

int gcd(int a, int b){return (b==0)? a : gcd(b, a%b);}

void simplify(int *numerator, int *denominator){
    int common = gcd(*numerator, *denominator);
    *numerator /= common;
    *denominator /= common;
}

void add(int *a, int *b, int *c, int *d){
    // printf("%d, %d, %d, %d\n", *a, *b, *c, *d);
    int numerator = *a * *d + *b * *c;
    int denominator = *b * * d;
    // printf("numerator = %d, denominator = %d\n", numerator, denominator);
    simplify(&numerator, &denominator);
    // printf("numerator = %d, denominator = %d\n", numerator, denominator);
    output(numerator, denominator);
}

void minus(int *a, int *b, int *c, int *d){
    int numerator = *a * *d - *b * *c;
    int denominator = *b * * d;
    simplify(&numerator, &denominator);
    output(numerator, denominator);
}

void multiply(int *a, int *b, int *c, int *d){
    int numerator = *a * *c;
    int denominator = *b * * d;
    simplify(&numerator, &denominator);
    output(numerator, denominator);
}

void divide(int *a, int *b, int *c, int *d){
    int numerator = *a * *d;
    int denominator = *b * * c;
    simplify(&numerator, &denominator);
    output(numerator, denominator);
}

int main(){
    char fraction1[50], fraction2[50];
    scanf("%s", fraction1);
    scanf("%s", fraction2);

    int numerator1, denominator1;
    int numerator2, denominator2;
    if(strchr(fraction1, '(')){
        int n1;
        sscanf(fraction1, "%d(%d/%d)", &n1, &numerator1, &denominator1);
        // numerator1 = (n1>0)? numerator1+n1*denominator1 : n1*denominator1-;
        if(n1>0) numerator1 += n1*denominator1;
        else if(n1<0) numerator1 = n1*denominator1-numerator1;
        else {printf("error\n"); return 0;}
    }else{
        sscanf(fraction1, "%d/%d", &numerator1, &denominator1);
    }

    if(strchr(fraction2, '(')){
        int n2;
        sscanf(fraction2, "%d(%d/%d)", &n2, &numerator2, &denominator2);
        // numerator2 = (n2>0)? numerator2+n2*denominator2 : -(numerator2-n2*denominator2); 
        if(n2>0) numerator2 += n2*denominator2;
        else if(n2<0) numerator2 = n2*denominator2-numerator2;
        else {printf("error\n"); return 0;}
    }else{
        sscanf(fraction2, "%d/%d", &numerator2, &denominator2);
    }
    // printf("%d, %d\n", numerator1, denominator1);
    // printf("%d, %d\n", numerator2, denominator2);
    if(denominator1 == 0 || denominator2 == 0) {printf("error\n"); return 0;}
    add(&numerator1, &denominator1, &numerator2, &denominator2);
    minus(&numerator1, &denominator1, &numerator2, &denominator2);
    multiply(&numerator1, &denominator1, &numerator2, &denominator2);
    divide(&numerator1, &denominator1, &numerator2, &denominator2);
}