#include <stdio.h>
#include <math.h>

int main(){
    int a, b, c;
    float x1, x2;
    float realPart;

    scanf("%d%d%d", &a, &b, &c);
    
    if ((b*b - 4*a*c >= 0))
    {
        x1 = ((-b) + sqrt(b * b - 4 * a * c)) / (2 * a);
        x2 = ((-b) - sqrt(b * b - 4 * a * c)) / (2 * a);
        printf("%.1f\n", x1);
        printf("%.1f", x2);
    }else
    {
        realPart = (float)(-b) / (float)(2 * a);
        x1 = ( -b ) / ( 2 * a ) + ( sqrt( -1 * ( b * b - 4 * a * c )) / ( 2 * a ));
        x2 = ( -b ) / ( 2 * a ) - ( sqrt( -1 * ( b * b - 4 * a * c )) / ( 2 * a ));
        printf("%.1f+%.1fi\n", realPart, x1);
        if(x2>0){
            printf("%.1f%+.1fi", realPart, x2);
        }else{
            printf("%.1f%.1fi", realPart, x2);
        }
        
    }
    
    return 0;
}