#include<stdio.h>
#include<stdlib.h>

typedef struct dice {
    int up, down, left, right, ffront, bback;
} Dice;

void init_dice(Dice *d) {
    d->up = 1;
    d->down = 6;
    d->left = 5;
    d->right = 2;
    d->ffront = 4;
    d->bback = 3;
}
/////
int check(int first_dice, int second_dice){
    return (first_dice == second_dice)? 1:0;
}
int who_is_larger(int first_dice, int second_dice){
    return (first_dice>=second_dice)? first_dice : second_dice;
}
int check3(int dice1, int dice2, int dice3){
    return (check(dice1, dice2) && check(dice2, dice3))? 1 : 0;
}
void calculate_score(int dice1, int dice2, int dice3, int dice4){
    if(check(dice1, dice2) && check(dice2, dice3) && check(dice3, dice4)) printf("18\n");
    else if(check(dice1, dice2) && check(dice3, dice4)){
        printf("%d\n", 2*(who_is_larger(dice1, dice3)));
    }else if(check(dice1, dice3) && check(dice2, dice4)){
        printf("%d\n", 2*(who_is_larger(dice1, dice2)));
    }else if(check(dice1, dice4) && check(dice2, dice3)){
        printf("%d\n", 2*(who_is_larger(dice1, dice2)));
    }else if(check3(dice1, dice2, dice3)){
        printf("0\n");
    }else if(check3(dice1, dice2, dice4)){
        printf("0\n");
    }else if(check3(dice1, dice3, dice4)){
        printf("0\n");
    }else if(check3(dice2, dice3, dice4)){
        printf("0\n");
    }else if(check(dice1, dice2)){
        printf("%d\n", dice3+dice4);
    }else if(check(dice1, dice3)){
        printf("%d\n", dice2+dice4);
    }else if(check(dice1, dice4)){
        printf("%d\n", dice2+dice3);
    }else if(check(dice2, dice3)){
        printf("%d\n", dice1+dice4);
    }else if(check(dice2, dice4)){
        printf("%d\n", dice1+dice3);
    }else if(check(dice3, dice4)){
        printf("%d\n", dice1+dice2);
    }else{
        printf("0\n");
    }
}

int main() {
    int m, a, b, N;
    int op;
    Dice arr[5];
    scanf("%d", &N);
    
    for (int i = 1; i <= 4; i++) {
        init_dice(&arr[i]);
    }

    for(int j=0; j<N; j++){
        for(int i=1; i<=4; i++){
            scanf("%d", &op);
            if(op == 1){            // front
                int temp = arr[i].up;
                arr[i].up = arr[i].bback;
                arr[i].bback = arr[i].down;
                arr[i].down = arr[i].ffront;
                arr[i].ffront = temp;
            }else if(op == 2){      // back
                int temp = arr[i].up;
                arr[i].up = arr[i].ffront;
                arr[i].ffront = arr[i].down;
                arr[i].down = arr[i].bback;
                arr[i].bback = temp;
            }else if(op ==3){       // right
                int temp = arr[i].up;
                arr[i].up = arr[i].left;
                arr[i].left = arr[i].down;
                arr[i].down = arr[i].right;
                arr[i].right = temp;
            }else if(op == 4){      // left
                int temp = arr[i].up;
                arr[i].up = arr[i].right;
                arr[i].right = arr[i].down;
                arr[i].down = arr[i].left;
                arr[i].left = temp;
            }
        }
    }
    // for (int i = 1; i <= 4; i++) {
    //     printf("%d ", arr[i].up);
        
    // }
    
    calculate_score(arr[1].up, arr[2].up, arr[3].up, arr[4].up);

    return 0;
}

/*
2
1 2 3 4
4 3 2 1
*/
