// #include <stdio.h>

// int main(){
//     int type, n;
//     scanf("%d %d", &type, &n);
//     if(type == 1){
//         for(int i=0; i<n; i++){
//             for(int j=0; j<n-i-1; j++) printf("#");
//             for(int j=i+1; j>1; j--) printf("%d", j);
//             for(int j=1; j<=i+1; j++) printf("%d", j);
//             for(int j=0; j<n-i-1; j++) printf("#");
//             printf("\n");
//         }
//         for(int i=n-1; i>0; i--){
//             for(int j=n-i; j>0; j--) printf("#");
//             for(int j=i; j>1; j--) printf("%d", j);
//             for(int j=1; j<=i; j++) printf("%d", j);
//             for(int j=n-i; j>0; j--) printf("#");
//             printf("\n");
//         }
//     }else if(type == 2){
//         for(int i=0; i<n; i++){
//             for(int j=1; j<=i+1; j++) printf("%d", j);
//             for(int j=n-i-1; j>0; j--) printf("#");
//             printf("\n");
//         }
//         for(int i=n; i>0; i--){
//             for(int j=i; j>0; j--) printf("%d", j);
//             for(int j=n-i; j>0; j--) printf("#");
//             printf("\n");
//         }
//     }else if(type == 3){
//         for(int i=0; i<n; i++){
//             for(int j=2*(n-i-1); j>0; j--) printf("#");
//             for(int j=1; j<i+1; j++) printf("%d", j);
//             for(int j=i+1; j>0; j--) printf("%d", j);
//             printf("\n");
//         }
//     }else if(type == 4){
//         for(int i=0; i<n; i++){
//             for(int j=n-i-1; j>0; j--) printf("#");
//             if(i%2 == 0) printf("12345");
//             else printf("54321");
//             for(int j=0; j<i; j++) printf("#");
//             printf("\n");
//         }
//     }
// }


// #include <stdio.h>

// int main(){
//     int m, n;
//     scanf("%d %d", &m, &n);
//     if(m == 1){
//         for(int i=0; i<n; i++){
//             for(int j=n-i-1; j>0; j--) printf("#");
//             for(int j=i+1; j>1; j--) printf("%d", j);
//             for(int j=1; j<=i+1; j++) printf("%d", j);
//             for(int j=n-i-1; j>0; j--) printf("#");
//             printf("\n");
//         }
//         for(int i=0; i<n-1; i++){
//             for(int j=1; j<=i+1; j++) printf("#");
//             for(int j=n-i-1; j>1; j--) printf("%d", j);
//             for(int j=1; j<=n-i-1; j++) printf("%d", j);
//             for(int j=1; j<=i+1; j++) printf("#");
//             printf("\n");
//         }
//     }else if(m ==2){
//         for(int i=0; i<n; i++){
//             for(int j=1; j<=i+1; j++) printf("%d", j);
//             for(int j=n-i-1; j>0; j--) printf("#");
//             printf("\n");
//         }
//         for(int i=0; i<n; i++){
//             for(int j=n-i; j>0; j--) printf("%d", j);
//             for(int j=0; j<i; j++) printf("#");
//             printf("\n");
//         }
//     }else if(m ==3){
//         for(int i=0; i<n; i++){
//             for(int j=2*(n-i-1); j>0; j--) printf("#");
//             for(int j=1; j<i+1; j++) printf("%d", j);
//             for(int j=i+1; j>0; j--) printf("%d", j);
//             printf("\n");
//         }
//     }else if(m ==4){
//         for(int i=0; i<n; i++){
//             for(int j=n-i-1; j>0; j--) printf("#");
//             (i%2 == 0)? printf("12345") : printf("54321");
//             for(int j=0; j<i; j++) printf("#");
//             printf("\n");
//         }
//     }
// }
/*
#include <stdio.h>

int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    if(m==1){
        for(int i=0; i<n; i++){
            for(int j=n-i-1; j>0; j--) printf("#");
            for(int j=i+1; j>1; j--) printf("%d", j);
            for(int j=1; j<=i+1; j++) printf("%d", j);
            for(int j=n-i-1; j>0; j--) printf("#");
            printf("\n");
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<i+1; j++) printf("#");
            for(int j=n-i; j>1; j--) printf("%d", j);
            for(int j=1; j<=n-i; j++) printf("%d", j);
            for(int j=1; j<i+1; j++) printf("#");
            printf("\n");
        }
    }
    else if(m==2)
    {
        for(int i=0; i<n; i++){
            for(int j=1; j<=i+1; j++) printf("%d", j);
            for(int j=n-i-1; j>0; j--) printf("#");
            printf("\n");
        }
        for(int i=0; i<n; i++){
            for(int j=n-i; j>0; j--) printf("%d", j);
            for(int j=0; j<i; j++) printf("#");
            printf("\n");
        }
    }
    else if(m==3)
    {
        for(int i=0; i<n; i++){
            for(int j=2*(n-i-1); j>0; j--) printf("#");
            for(int j=1; j<=i; j++) printf("%d", j);
            for(int j=i+1; j>0; j--) printf("%d", j);
            printf("\n");
        }
    }
    else if(m==4)
    {
        for(int i=0; i<n; i++){
            for(int j=n-i-1; j>0; j--) printf("#");
            (i%2==0)? printf("12345") : printf("54321");
            for(int j=0; j<i; j++) printf("#");
            printf("\n");
        }
    }
}
*/
#include <stdio.h>

int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    if(m==1){
        for(int i=0; i<n; i++){
            for(int j=n-i-1; j>0; j--) printf("#");
            for(int j=i+1; j>1; j--) printf("%d", j);
            for(int j=1; j<=i+1; j++) printf("%d", j);
            for(int j=n-i-1; j>0; j--) printf("#");
            printf("\n");
        }
        for(int i=0; i<n-1; i++){
            for(int j=0; j<i+1; j++) printf("#");
            for(int j=n-i-1; j>1; j--) printf("%d", j);
            for(int j=1; j<=n-i-1; j++) printf("%d", j);
            for(int j=0; j<i+1; j++) printf("#");
            printf("\n");
        }
    }else if(m==2){
        for(int i=0; i<n; i++){
            for(int j=1; j<=i+1; j++) printf("%d", j);
            for(int j=n-i-1; j>0; j--) printf("#");
            printf("\n");
        }
        for(int i=0; i<n; i++){
            for(int j=n-i; j>0; j--) printf("%d", j);
            for(int j=0; j<i; j++) printf("#");
            printf("\n");
        }
    }else if(m==3){
        for(int i=0; i<n; i++){
            for(int j=2*(n-i-1); j>0; j--) printf("#");
            for(int j=1; j<=i; j++) printf("%d", j);
            for(int j=i+1; j>0; j--) printf("%d", j);
            printf("\n");
        }
    }else if(m==4){
        for(int i=0; i<n; i++){
            for(int j=n-i-1; j>0; j--) printf("#");
            if(i%2==0) for(int j=n; j>0; j--) printf("%d", j);
            else for(int j=1; j<=n; j++) printf("%d", j);
            for(int j=0; j<i; j++) printf("#");
            printf("\n");
        }
    }
}