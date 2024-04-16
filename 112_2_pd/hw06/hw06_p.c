// #include <stdio.h>

// void print_9(int N, int i){
//     for(int j=N-i-1; j>0; j--) printf("#");
// }
// void print_star_letter(int i){
//     for(int j=0; j<i; j++) printf("*%c", 'A'+(i-1)%3);
// }
// int main(){
//     int N, M;
//     scanf("%d %d", &M, &N);
//     if(M == 1 && N>=2 && N<=9){
//         for(int i=0; i<N; i++){
//             print_9(N, i);
//             print_star_letter(i);
//             printf("*");
//             print_9(N, i);
//             printf("\n");
//         }
//     }else if(M == 2 && N>=2 && N<=9){
//         for(int i=0; i<N; i++){
//             for(int j=1; j<=i+1; j++) printf("%d", j);
//             for(int j=2*(N-i); j>0; j--) printf("#");
//             for(int j=i+1; j>0; j--) printf("%d", j);
//             printf("\n");
//         }
//     } else{
//         printf("error\n");
//     }
// }

#include <stdio.h>

int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    if(m==1){
        for(int i=0; i<n; i++){
            for(int j=n-i-1; j>0; j--) printf("#");
            for(int j=0; j<i; j++) printf("*%c", 'A'+(i-1)%3);
            printf("*");
            for(int j=n-i-1; j>0; j--) printf("#");
            printf("\n");
        }
    }else if(m==2){
        for(int i=0; i<n; i++){
            for(int j=1; j<=i+1; j++) printf("%d", j);
            for(int j=2*(n-i); j>0; j--) printf("*");
            for(int j=i+1; j>0; j--) printf("%d", j);
            printf("\n");
        }
    }
}