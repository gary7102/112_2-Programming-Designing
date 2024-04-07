#include <stdio.h>

int main(){
    float weight, height;
    float bmi;

    scanf("%f", &weight);
    scanf("%f", &height);
    height = height/100;

    bmi = (weight)/(height*height);
    printf("%.1f", bmi);
}