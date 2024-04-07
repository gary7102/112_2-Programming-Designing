#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 102 // 考慮到最多100位數加上可能的進位和終止符
#define OUTPUT_LENGTH 201
void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// 判斷字符串表示的數字大小，返回1如果a>b，0如果a==b，-1如果a<b
int compare(char a[], char b[]) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    if(a[lenA-1] == '-') lenA--;
    if(b[lenB-1] == '-') lenB--;

    if (lenA > lenB) return 1;
    if (lenA < lenB) return -1;
    for (int i = 0; i < lenA; i++) {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return -1;
    }
    return 0;
}

// 大數加法
void add(char a[], char b[], char result[]) {
    int i = 0, carry = 0;
    if(a[strlen(a)-1] == '-') a[strlen(a)-1] ='\0';
    if(b[strlen(b)-1] == '-') b[strlen(b)-1] ='\0';

    for (; a[i] != '\0' || b[i] != '\0'; i++) {
        int digitA = a[i] ? a[i] - '0' : 0;
        int digitB = b[i] ? b[i] - '0' : 0;
        int sum = digitA + digitB + carry;
        result[i] = (sum % 10) + '0';
        carry = sum / 10;
    }
    if (carry) {
        result[i++] = carry + '0';
    }
    result[i] = '\0';
    reverse(result);
}

// 大數減法
void subtract(char a[], char b[], char result[]) {
    if(a[strlen(a)-1] == '-') a[strlen(a)-1] ='\0';
    if(b[strlen(b)-1] == '-') b[strlen(b)-1] ='\0';

    int i = 0, borrow = 0;
    for (; a[i] != '\0'; i++) {
        int digitA = a[i] - '0';
        int digitB = b[i] ? b[i] - '0' : 0;
        int sub = digitA - digitB - borrow;
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[i] = sub + '0';
    }
    while (i > 1 && result[i-1] == '0') i--; // 移除前導零
    result[i] = '\0';
    reverse(result);
}

void multiply(char a[], char b[], char result[]) {
    int len1 = strlen(a), len2 = strlen(b);
    if(a[strlen(a)-1] == '-'){
        a[strlen(a)-1] ='\0';
        len1--;
    } 
    if(b[strlen(b)-1] == '-') {
        b[strlen(b)-1] ='\0';
        len2--;
    }
    char tempResult[OUTPUT_LENGTH] = {0};

    for (int i = 0; i < len1; i++) {
        int carry = 0;
        for (int j = 0; j < len2; j++) {
            int digit1 = a[i] - '0';
            int digit2 = b[j] - '0';
            int temp = tempResult[i + j] ? tempResult[i + j] - '0' : 0;
            int sum = digit1 * digit2 + temp + carry;
            tempResult[i + j] = (sum % 10) + '0';
            carry = sum / 10;
        }
        if (carry) {
            tempResult[i + len2] = carry + '0';
        }
    }
    reverse(tempResult);
    strcpy(result, tempResult);
}


int main() {
    char num1[MAX_LENGTH], num2[MAX_LENGTH], sum[OUTPUT_LENGTH], sub[OUTPUT_LENGTH], product[OUTPUT_LENGTH];
    memset(num1, 0, sizeof(num1));
    memset(num2, 0, sizeof(num2));
    memset(sum, 0, sizeof(sum));
    memset(sub, 0, sizeof(sub));
    memset(product, 0, sizeof(product));
    
    // 輸入
    scanf("%s %s", num1, num2);

    // 數字反轉，以便從最低位開始操作
    reverse(num1);
    reverse(num2);

    if(num1[strlen(num1)-1] == '-'){
        if(num2[strlen(num2)-1] == '-'){        
            if(compare(num1, num2)>0){          //(-, -) 且 a>b
                printf("-");
                add(num1, num2, sum);
                printf("%s\n", sum);
                
                printf("-");
                subtract(num1, num2, sub);
                printf("%s\n", sub);
                
            }else if(compare(num1, num2)<0){    //(-, -) 且 a<b
                printf("-");
                add(num2, num1, sum);
                printf("%s\n", sum);

                subtract(num2, num1, sub);
                printf("%s\n", sub);
            }else{
                printf("-");                    //(-, -) 且 a=b
                add(num1, num2, sum);
                printf("%s\n", sum);

                printf("0\n");
            }
            multiply(num1, num2, product);      //(-, -)
            printf("%s\n", product);
        }else{
            if(compare(num1, num2)>0){          //(-, +) 且 a>b
                printf("-");
                subtract(num1, num2, sum);
                printf("%s\n", sum);

                printf("-");
                add(num1, num2, sub);
                printf("%s\n", sub);
            }else if(compare(num1, num2)<0){    //(-, +) 且 a<b
                subtract(num2, num1, sum);
                printf("%s\n", sum);

                printf("-");
                add(num1, num2, sub);
                printf("%s\n", sub);
            }else{
                printf("0\n");                  //(-, +) 且 a=b

                printf("-");
                add(num1, num2, sub);
                printf("%s\n", sub);
            }
            printf("-");
            multiply(num1, num2, product);      //(-, +)
            printf("%s\n", product);
        }
    }else{
        if(num2[strlen(num2)-1] == '-'){    
            if(compare(num1, num2)>0){          //(+, -) 且 a>b
                subtract(num1, num2, sum);
                printf("%s\n", sum);

                add(num1, num2, sub);
                printf("%s\n", sub);
            }else if(compare(num1, num2)<0){    //(+, -) 且 a<b
                printf("-");
                subtract(num2, num1, sum);
                printf("%s\n", sum);

                add(num1, num2, sub);
                printf("%s\n", sub);
            }else{
                printf("0\n");                  //(+, -) 且 a=b

                add(num1, num2, sub);
                printf("%s\n", sub);
            }
            printf("-");
            multiply(num1, num2, product);      //(+, -)
            printf("%s\n", product);
        }else{                 
            if (compare(num1, num2)>0)
            {
                add(num1, num2, sum);           //(+, +) 且 a>b
                printf("%s\n", sum);

                subtract(num1, num2, sub);
                printf("%s\n", sub);
            }else if(compare(num1, num2)<0){
                add(num1, num2, sum);           //(+, +) 且 a<b
                printf("%s\n", sum);

                printf("-");
                subtract(num2, num1, sub);
                printf("%s\n", sub);
            }else{
                add(num1, num2, sum);           //(+, +) 且 a=b
                printf("%s\n", sum);

                printf("0\n");
            }
            multiply(num1, num2, product);      //(+, +)
            printf("%s\n", product);
        }
    }
    
    return 0;
}