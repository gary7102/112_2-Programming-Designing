#include <stdio.h>
#include <string.h>
#include <math.h>

void ten_to_new(int base, int decimal){
    char new_base_Num[100];
    int temp=0, i=0;
    while(decimal != 0){
        temp  = decimal % base;
        if(temp<10){
            temp+=48;
        }else{
            temp+=55;
        }
        new_base_Num[i++] = temp;
        decimal/=base;
    }
    
    for (int j = i - 1; j >= 0; j--) 
        printf("%c", new_base_Num[j]); 
    return;
}

void init_to_ten(int base, char input[], int new){
    int decimal=0;
    int len = strlen(input);

    for(int i = len-1; i>=0; i--){
        printf("%d\n", input[len-i-1]);
        if (input[len-i-1] >= '0' && input[len-i-1] <= '9'){
            decimal += pow(base, i)*(input[len-i-1]-'0');
        }else{
            decimal += pow(base, i)*(input[len-i-1]-'A'+10);
        }
    }
    if(decimal == 0){
        printf("0\n");
        return;
    }
    ten_to_new(new, decimal);
}

int main(){
    int init_base, new_base;
    char input[10];
    scanf("%d", &init_base);
    scanf("%s", &input);
    scanf("%d", &new_base);
    init_to_ten(init_base, input, new_base);
}