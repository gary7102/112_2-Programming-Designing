#include <stdio.h>
#include <string.h>

int main(){
    int N;
    
    scanf("%d", &N);
    int arr[N];
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    int count=0;
    int arr_length = sizeof(arr)/sizeof(arr[0]);
    
    for(int i=0; i<arr_length-1; i++){
        for (int j=i+1; j<arr_length; j++){
            if(arr[i]>arr[j]){
                count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}