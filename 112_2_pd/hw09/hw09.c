#include <stdio.h>
#include <string.h>

int calculateFeedback(int N, int count) {
    
    if (N == 0 || N == 1) {
        return count;
    }
    else if (N % 2 == 0) {
        count++;
        return calculateFeedback(N / 2, count);
    }
    else {
        count++;
        return calculateFeedback((N + 1) / 2, count);
    }
}
void decimal_to_binary(int n){
    int binaryNum[1000]; 
  
    int i = 0; 
    while (n > 0) { 
  
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
    for(int j = 0; j<(14-i); j++){
        printf("0");
    }
    
    for (int j = i - 1; j >= 0; j--) 
        printf("%d", binaryNum[j]); 
    printf("\n");
}
int main() {
    int N;
    int count = 0;
    int count_calculateFeedback = 0;
    int feedback = 0;
    int dec_value = 0;
    while (1)
    {
       
        scanf("%d", &N);

        dec_value = 0; 
        feedback = 0;

        if(count%2 == 0){
            int num = N; 
            dec_value = 0; 
            int base = 1; 
        
            int temp = num; 
            while (temp) {
                int last_digit = temp % 10; 
                temp = temp / 10; 
                dec_value += last_digit * base; 
                base = base * 2; 
            }
            // printf("%d\n", dec_value);
        }

        if((count%2 == 1) && (N == -1)) break;
        else if((count%2 == 1) && (N == 0)) {
            count++;
            continue;
        }
        else{
            for(int i=0; i<=dec_value; i++){
                feedback += calculateFeedback(i, count_calculateFeedback);
            }
            decimal_to_binary(feedback);
            // printf("%014d\n", output);
            count++;
        }
    }
    return 0;
}
