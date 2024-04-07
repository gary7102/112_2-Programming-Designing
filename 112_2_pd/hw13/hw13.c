#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void simplifyFraction(int *numerator, int *denominator) {
    int g = gcd(abs(*numerator), abs(*denominator));
    *numerator /= g;
    *denominator /= g;
    if (*denominator < 0) {
        *denominator *= -1;
        *numerator *= -1;
    }
}

int main(){
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        int m_numerator = y1 - y2;
        int m_denominator = x1 - x2;
        int b_numerator = x2*y1 - x1*y2;
        int b_denominator = x2-x1;

        simplifyFraction(&m_numerator, &m_denominator);
        simplifyFraction(&b_numerator, &b_denominator);

         if(m_numerator == 0) {
            printf("y = %d\n", b_numerator / b_denominator);
        } else {
            if (m_numerator == m_denominator) {
                printf("y = x");
            } else if (m_numerator == -m_denominator) {
                printf("y = -x");
            } else if (m_denominator == 1) {
                printf("y = %dx", m_numerator);
            } else {
                printf("y = %d/%dx", m_numerator, m_denominator);
            }

            if (b_numerator > 0) {
                if (b_denominator == 1) {
                    printf(" + %d", b_numerator);
                } else {
                    printf(" + %d/%d", b_numerator, b_denominator);
                }
            } else if (b_numerator < 0) {
                if (b_denominator == 1) {
                    printf(" - %d", abs(b_numerator));
                } else {
                    printf(" - %d/%d", abs(b_numerator), b_denominator);
                }
            }
            printf("\n");
        }
    }
    return 0;
}