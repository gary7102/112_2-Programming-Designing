#include <stdio.h>
#include <math.h>

int generate_gray_code(int n, int k){
    if(n == 1){
        printf("%d", k);
        printf("\n");
        return 0;
    } 

    if(k < pow(2, (n-1))){
        printf("0");
        return generate_gray_code(n-1, k);
    }else if(k >= pow(2, (n-1))){
        printf("1");
        return generate_gray_code(n-1, pow(2, (n))-1-k);
    }
}

int main(){
    int n, k, no;
    scanf("%d", &n);
    if(n == -1) return 0;
    scanf("%d", &k);
    while (n != -1)
    {
        no = generate_gray_code(n, k);
        scanf("%d", &n);
        if(n == -1) break;
        scanf("%d", &k);
    }
}