#include <stdio.h>

int OutputOne(int m){
    int character = 1;
    for(int i=0; i<m; i++){

        for(int j = i; j<m-1; j++){
            printf("#");
        }
        printf("*");
        if(i>=1){
            for(int j=0; j<i; j++){
                if(character%3 == 1){
                    printf("A");
                }else if(character%3 == 2){
                    printf("B");
                }else{
                    printf("C");
                }
                printf("*");
            }
            character++;
            if(character == 3) character == 1;
        }
        
        for(int j = m-i-1; j>0; j--){
            printf("#");
        }

        printf("\n");
    }

}

void OutputTwo(int m){
    
    for(int i=1; i<=m; i++){
        for(int j=1; j<=i; j++){
            printf("%d", j);
        }
        int star = (m-i+1)*2;
        for(star; star>0; star--){
            printf("*");
        }
        for(int j=i; j>0; j--){
            printf("%d", j);
        }
        printf("\n");
    }
}

int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    if((M<2 || M>9)){
        printf("error");
        return 0;
    }
    if(N == 1){
        OutputOne(M);
    }else if(N == 2){
        OutputTwo(M);
    }else{
        printf("error");
        return 0;
    }
}