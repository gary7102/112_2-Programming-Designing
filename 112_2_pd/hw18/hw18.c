#include <stdio.h>
#define SWAP(x,y) {int t; t = x; x = y; y = t;}

int getMinIndex(int d[], int left, int right) {
    int i=0, minIndex = left;
    for ((i=left+1); i<right; i++) {
        if (d[i]<d[minIndex]) minIndex=i;
    }
    return minIndex;
}
int check(int after, int prev){
    if(after!=prev) return 1;
    return 0;
}
void selectSort(int d[], int n) {
    int i=0, after_index=0, count =0;
    for (i=0; i<n; i++) {
        after_index = getMinIndex(d, i, n);
        if(check(after_index ,i)) count++;
        SWAP(d[i], d[after_index]);
    }
    int compare=0;
    for (int i = 0; i < n; i++){
        compare+=i;
    }
    
    printf("%d %d\n", compare, 3*count);
}

void InsertionSort(int a[], int n) {
    int target=0, i=0, j=0, compare_j=0, compare_target=0, move=0;
    for (i=1; i<n; i++) {
        target = a[i];
        move++;
        for (j=i; (j>0) &&(a[j-1]>target) ; j--){
            compare_j++; compare_target++;
            a[j] = a[j-1];
            move++;
        }
        
        if(a[j-1]<= target && j>0){
            compare_j++; 
            compare_target++;
        } else if(j <= 0){
            compare_j++; 
        }

        a[j] = target;
        move++;
    }
    
    printf("%d %d\n" , compare_j+compare_target, move);
}

int main(){
    int N;
    scanf("%d", &N);
    int select_arr[N], insertion_arr[N];
    for(int i=0; i<N; i++){
        scanf("%d", &select_arr[i]);
        insertion_arr[i] = select_arr[i];
    }
    
    selectSort(select_arr, N);
    // print(select_arr, N);
    // print(insertion_arr, N);
    InsertionSort(insertion_arr, N);
}