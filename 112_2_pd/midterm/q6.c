// #include <stdio.h>

// typedef struct dice{
//     int up, down, front, back, left, right;
// }Dice;

// void init_dice(Dice *d){
//     d->up = 1;
//     d->down = 6;
//     d->front = 4;
//     d->back = 3;
//     d->right = 2;
//     d->left = 5;
// }

// int main(){
//     int n, op;
//     Dice arr_A[3];
//     Dice arr_B[3];
//     scanf("%d", &n);
//     for(int i=1; i<=2; i++) init_dice(&arr_A[i]);
    
//     for(int j=0; j<n; j++){
//         for(int i=1; i<=2; i++){
//             scanf("%d", &op);
//             if(op == 1){        //front
//                 int temp = arr_A[i].up;
//                 arr_A[i].up = arr_A[i].back;
//                 arr_A[i].back = arr_A[i].down;
//                 arr_A[i].down = arr_A[i].front;
//                 arr_A[i].front = temp;
//             }else if(op ==2){       //left
//                 int temp = arr_A[i].up;
//                 arr_A[i].up = arr_A[i].right;
//                 arr_A[i].right = arr_A[i].down;
//                 arr_A[i].down = arr_A[i].left;
//                 arr_A[i].left = temp;
//             }else if(op ==3){       //right
//                 int temp = arr_A[i].up;
//                 arr_A[i].up = arr_A[i].left;
//                 arr_A[i].left = arr_A[i].down;
//                 arr_A[i].down = arr_A[i].right;
//                 arr_A[i].right = temp;
//             }
//         }
//     }
     

//     scanf("%d", &n);
//     for(int i=1; i<=2; i++) init_dice(&arr_B[i]);
//     for(int j=0; j<n; j++){
//         for(int i=1; i<=2; i++){
//             scanf("%d", &op);
//             if(op == 1){        //front
//                 int temp = arr_B[i].up;
//                 arr_B[i].up = arr_B[i].back;
//                 arr_B[i].back = arr_B[i].down;
//                 arr_B[i].down = arr_B[i].front;
//                 arr_B[i].front = temp;
//             }else if(op ==2){       //left
//                 int temp = arr_B[i].up;
//                 arr_B[i].up = arr_B[i].right;
//                 arr_B[i].right = arr_B[i].down;
//                 arr_B[i].down = arr_B[i].left;
//                 arr_B[i].left = temp;
//             }else if(op ==3){       //right
//                 int temp = arr_B[i].up;
//                 arr_B[i].up = arr_B[i].left;
//                 arr_B[i].left = arr_B[i].down;
//                 arr_B[i].down = arr_B[i].right;
//                 arr_B[i].right = temp;
//             }
//         }
//     }
//     printf("%d %d %d %d %d %d\n", arr_A[1].front, arr_A[1].up, arr_A[1].back, arr_A[1].down, arr_A[1].right, arr_A[1].left);
//     printf("%d %d %d %d %d %d\n", arr_A[2].front, arr_A[2].up, arr_A[2].back, arr_A[2].down, arr_A[2].right, arr_A[2].left);
//     printf("%d %d %d %d %d %d\n", arr_B[1].front, arr_B[1].up, arr_B[1].back, arr_B[1].down, arr_B[1].right, arr_B[1].left);
//     printf("%d %d %d %d %d %d\n", arr_B[2].front, arr_B[2].up, arr_B[2].back, arr_B[2].down, arr_B[2].right, arr_B[2].left);

//     int A_score=0, B_score=0;
//     A_score = (arr_A[1].up == arr_A[2].up)?  arr_A[1].up : arr_A[1].up*arr_A[2].up;
//     B_score = (arr_B[1].up == arr_B[2].up)?  arr_B[1].up : arr_B[1].up*arr_B[2].up;
//     if(A_score > B_score){
//         printf("A win\n");
//     }else if(A_score < B_score){
//         printf("B win\n");
//     }else{
//         printf("Tie");
//     }
// }

#include <stdio.h>
#include <string.h>

typedef struct dice{
    int up, down, left, right, front, back;
}Dice;

void init_dice(Dice *d){
    d->up=1;
    d->down=6;
    d->front=4;
    d->back=3;
    d->right=2;
    d->left=5;
}

int main(){
    int A_plays=0, B_plays=0, op=0;
    Dice arr_A[3];
    Dice arr_B[3];
    for(int i=1; i<=2; i++) init_dice(&arr_A[i]);
    scanf("%d", &A_plays);
    for(int j=0; j<A_plays; j++){
        for(int i=1; i<=2; i++){
            scanf("%d", &op);
            if(op==1){
                int temp=arr_A[i].up;
                arr_A[i].up = arr_A[i].back;
                arr_A[i].back = arr_A[i].down;
                arr_A[i].down = arr_A[i].front;
                arr_A[i].front = temp;
            }else if(op == 2){
                int temp=arr_A[i].up;
                arr_A[i].up = arr_A[i].right;
                arr_A[i].right = arr_A[i].down;
                arr_A[i].down = arr_A[i].left;
                arr_A[i].left = temp;
            }else if(op == 3){
                int temp=arr_A[i].up;
                arr_A[i].up = arr_A[i].left;
                arr_A[i].left = arr_A[i].down;
                arr_A[i].down = arr_A[i].right;
                arr_A[i].right = temp;
            }
        }
    }

    for(int i=1; i<=2; i++) init_dice(&arr_B[i]);
    scanf("%d", &B_plays);
    for(int j=0; j<B_plays; j++){
        for(int i=1; i<=2; i++){
            scanf("%d", &op);
            if(op==1){
                int temp=arr_B[i].up;
                arr_B[i].up = arr_B[i].back;
                arr_B[i].back = arr_B[i].down;
                arr_B[i].down = arr_B[i].front;
                arr_B[i].front = temp;
            }else if(op == 2){
                int temp=arr_B[i].up;
                arr_B[i].up = arr_B[i].right;
                arr_B[i].right = arr_B[i].down;
                arr_B[i].down = arr_B[i].left;
                arr_B[i].left = temp;
            }else if(op == 3){
                int temp=arr_B[i].up;
                arr_B[i].up = arr_B[i].left;
                arr_B[i].left = arr_B[i].down;
                arr_B[i].down = arr_B[i].right;
                arr_B[i].right = temp;
            }
        }
    }

    printf("%d %d %d %d %d %d\n", arr_A[1].front, arr_A[1].up, arr_A[1].back, arr_A[1].down, arr_A[1].right, arr_A[1].left);
    printf("%d %d %d %d %d %d\n", arr_A[2].front, arr_A[2].up, arr_A[2].back, arr_A[2].down, arr_A[2].right, arr_A[2].left);
    printf("%d %d %d %d %d %d\n", arr_B[1].front, arr_B[1].up, arr_B[1].back, arr_B[1].down, arr_B[1].right, arr_B[1].left);
    printf("%d %d %d %d %d %d\n", arr_B[2].front, arr_B[2].up, arr_B[2].back, arr_B[2].down, arr_B[2].right, arr_B[2].left);
    
    // int scoreA, scoreB;
    int scoreA = (arr_A[1].up==arr_A[2].up)? arr_A[1].up : arr_A[1].up*arr_A[2].up;
    int scoreB = (arr_B[1].up==arr_B[2].up)? arr_B[1].up : arr_B[1].up*arr_B[2].up;
    if(scoreA>scoreB) printf("A win\n");
    else if(scoreB > scoreA) printf("B win\n");
    else printf("Tie\n");
}