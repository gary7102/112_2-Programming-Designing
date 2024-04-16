/*
#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int j=0; j<n; j++){
        char ans[50];
        scanf("%s", ans);

        if(*ans == '0' && strlen(ans) == 1) printf("integer\n");
        else if(*ans == '-' && *(ans+1) == '0') printf("error\n");
        else{
            int integer=0, fp=0, var=0, str=0, zero=0, fraction=0, para=0;

            for(int i=0; i<strlen(ans); i++){
                if(i==0 && *ans == '-') integer++;
                else if(i==0 && *ans == '0') {zero++; integer++;}
                else if((*(ans+i)>='0' && *(ans+i) <= '9')) integer++;
                else if(*(ans+i) == '/') fraction++;
                else if(*(ans+i) == '(' && *(ans+i+1) != ')') para++;
                else if(*(ans+i) == ')' && i+1 == strlen(ans)) para++;
                else if(*(ans+i) == '.' && i+1!=strlen(ans)) fp++;      // 0. or 1. is string
                else if((*(ans+i)>='A' && *(ans+i) <= 'Z') || (*(ans+i)>='a' && *(ans+i) <= 'z') || (*(ans+i) == '_')) var++;
                else str++;
            }
            // printf("integer = %d, fp = %d, var = %d, str= %d, zero = %d, fraction = %d, para = %d\n", integer, fp, var, str, zero, fraction, para);
            if(integer == strlen(ans) && zero ==0 && fp == 0 && var == 0) printf("integer\n");
            else if(fraction == 1 && para==2){
                printf("algebraic fraction\n");
            }
            else if(fraction == 1){
                int count[2] = {0};
                int k=0, negative=0;
                if(*(ans) == '-') negative++;
                count[0]-=negative;
                for(int i=0; i<strlen(ans); i++){
                    if(*(ans+i) == '/') {k++; continue;}
                    count[k]++;
                }
                // printf("count[0] = %d, count[1] = %d", count[0], count[1]);

                if (count[0] < count[1])
                {
                    printf("proper fraction\n");
                }else if(count[0] > count[1]){
                    printf("improper fraction\n");
                }
                else{
                    for(int i=negative; i<=count[0]; i++){
                        if(*(ans+i) < *(ans+i+count[0]+1)) {printf("proper fraction\n"); break;}
                        else if(*(ans+i) > *(ans+i+count[0]+1)) {printf("improper fraction\n"); break;}
                    }
                }
                
            }
            else if(integer+fp == strlen(ans) && fp == 1){
                printf("float\n");
                for(int i=0; i<strlen(ans); i++) (*(ans+i) == '.')? printf("\n") : printf("%c", *(ans+i));
                printf("\n");
            } 
            else if(var+integer == strlen(ans) && zero == 0) printf("varialbe\n");
            else printf("error\n");
        }
    }
}
*/
/*
if 0 return integer
else if -0 return string
else 
    negative integer    
    0 && integer
    integer
    var
    string
*/
/*
#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int j=0; j<n; j++){
        char ans[50];
        scanf("%s", ans);

        if(*ans == '0' && strlen(ans) == 1) printf("integer\n");
        else if(*ans == '-' && *(ans+1) == '0' && strlen(ans) == 2) printf("error\n");
        else{
            int integer=0, fp=0, var=0, str=0, zero=0, fraction=0, para=0;
            for(int i=0; i<strlen(ans); i++){
                if(i==0 && *ans=='-') integer++;    // negative integer
                else if(i==0 && *ans=='0'){integer++; zero++;}  // zero and integer
                else if(*(ans+i)>='0' && *(ans+i)<='9') integer++;
                else if(*(ans+i) == '.' && i+1!=strlen(ans)) fp++;
                else if(*(ans+i)=='/') fraction++;
                else if(*(ans+i)=='(' && *(ans+i+1)!=')')para++;
                else if(*(ans+i)==')' && i+1==strlen(ans)) para++;
                else if((*(ans+i)>='A' && *(ans+i)<='Z') || (*(ans+i)>='a' && *(ans+i)<='z') || *(ans+i) == '_') var++;
                else str++;
            }
            // printf("integer = %d, fp = %d, var = %d, str = %d, zero = %d, fraction = %d, para = %d\n", integer, fp, var, str, zero, fraction, para);
            if(integer==strlen(ans) && zero==0 && var==0) printf("integer\n");
            else if(fraction==1 && para==2){
                printf("algebraic fraction\n");
            }
            else if(fraction==1){
                int count[2]={0};
                int negative=0;
                if(*ans=='-') negative++;
                count[0]-=negative;

                int k=0;
                for(int i=0; i<strlen(ans); i++){
                    if(*(ans+i) == '/') {k++; continue;}
                    count[k]++;
                }
                printf("negarive = %d, %d, %d\n", negative, count[0], count[1]);
                if(count[0] > count[1]){
                    printf("improper fraction\n");
                }else if(count[0] < count[1]){
                    printf("proper fraction\n");
                }else{
                    for(int i=negative; i<count[0]; i++){
                        if(*(ans+i) < *(ans+i+count[0]+1)) {printf("proper fraction\n"); break;}
                        else if(*(ans+i) > *(ans+i+count[0]+1)) {printf("improper fraction\n"); break;}
                    }
                }                
            }
            else if(fp==1 && fp+integer==strlen(ans)) {
                printf("float\n");
                for(int i=0; i<strlen(ans); i++) (*(ans+i)=='.')? printf("\n") : printf("%c", *(ans+i));
                printf("\n");
            }
            else if(integer+var==strlen(ans) && zero==0) printf("variable\n");
            else printf("error\n");
        }
    }
}
*/
/*
#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);

    for(int j=0; j<n; j++){
        char ans[50];
        scanf("%s", ans);

        if(*ans=='0' && strlen(ans)==1) printf("integer\n");
        else if(*ans=='-' && *(ans+1)=='0') printf("error\n");
        else{
            int integer=0, fp=0, var=0, str=0, zero=0, fraction=0, para=0;

            for(int i=0; i<strlen(ans); i++){
                if(i==0 && *ans=='-') integer++;
                else if(i==0 && *ans=='0') {zero++; integer++;}
                else if(*(ans+i)>='0' && *(ans+i)<='9') integer++;
                else if(*(ans+i)=='.' && i+1!=strlen(ans)) fp++;
                else if(*(ans+i)=='/') fraction++;
                else if(*(ans+i)=='(' && *(ans+i+1)!=')') para++;
                else if(*(ans+i)==')' && i+1==strlen(ans)) para++;
                else if((*(ans+i)>='A' && *(ans+i)<='Z') || (*(ans+i)>='a' && *(ans+i)<='z') || *(ans+i)=='_') var++;
                else str++;
            }
            // printf("integer=%d, fp=%d, var=%d, str=%d, zero=%d, fraction=%d, para=%d\n", integer, fp, var, str, zero, fraction, para);

            if(integer==strlen(ans) && zero==0 && var==0 && fp==0) printf("integer\n");
            else if(fraction==1 && para==2) printf("algebraic fraction\n");
            else if(fraction==1){
                int count[2]={0};
                int negative = (*ans=='-')? 1 : 0;
                count[0]-=negative;
                int k=0;
                for(int i=0; i<strlen(ans); i++){
                    if(*(ans+i)=='/') {k++; continue;}

                    count[k]++;
                }
                if(count[0]<count[1]){
                    printf("proper fraction\n");
                }else if(count[0]>count[1]){
                    printf("improper fraction\n");
                }else{
                    for(int i=negative; i<=count[0]; i++){
                        if(*(ans+i) < *(ans+i+count[0]+1)){printf("proper fraction\n"); break;}
                        else if(*(ans+i) > *(ans+i+count[0]+1)){printf("improper fraction\n"); break;}
                    } 
                }
            }
            else if(fp==1 && fp+integer==strlen(ans)){
                printf("float\n");
                for(int i=0; i<strlen(ans); i++) (*(ans+i)=='.')? printf("\n") : printf("%c", *(ans+i));
                printf("\n");
            } 
            else if(var+integer==strlen(ans) && zero==0) printf("variable\n");
            else printf("error\n");
        }
    }
}
*/
/*
#include <stdio.h>
#include <string.h>

int main(){
    int n;
    // char ans[50];
    scanf("%d", &n);
    for(int j=0; j<n; j++){
        char ans[50];
        scanf("%s", ans);
        if(*ans=='0' && strlen(ans)==1) printf("integer\n");
        else if(*ans=='-' && *(ans+1)=='0' && strlen(ans)==2) printf("error\n");
        else{
            int integer=0, fp=0, var=0, zero=0, fraction=0, para=0;
            for(int i=0; i<strlen(ans); i++){
                if(i==0 && *ans=='-') integer++;
                else if(i==0 && *ans=='0') {integer++; zero++;}
                else if(*(ans+i)>='0' && *(ans+i)<='9') integer++;
                else if(*(ans+i) == '.' && i+1!=strlen(ans)) fp++;
                else if(*(ans+i)=='(' && *(ans+i+1) != ')') para++;
                else if(*(ans+i)==')' && i+1==strlen(ans)) para++;
                else if(*(ans+i)=='/') fraction++;
                else if((*(ans+i)>='A' && *(ans+i)<='Z') || (*(ans+i)>='a' && *(ans+i)<='z') || *(ans+i)=='_') var++;
            }
            // printf("integer=%d, fp=%d, var=%d, zero=%d, fraction=%d, para=%d\n", integer, fp, var, zero, fraction, para);
            if(integer==strlen(ans)) printf("integer\n");
            else if(fp+integer==strlen(ans) && fp==1){
                for(int i=0; i<strlen(ans); i++) (*(ans+i)=='.')? printf("\n") : printf("%c", *(ans+i));
                printf("\n");
            }else if(para==2 && fraction==1) printf("algebraic fraction\n");
            else if(fraction==1){
                int count[2]={0};
                int negative = (*ans=='-')? 1 : 0;
                // count[0] -= negative;
                int k=0;
                for(int i=negative; i<strlen(ans); i++){
                    if(*(ans+i)=='/'){k++; continue;}
                    count[k]++;
                }
                // printf("count[0]=%d, count[1]=%d\n", count[0], count[1]);
                
                if(count[0] > count[1]) printf("improper fraction\n");
                else if(count[0] < count[1]) printf("proper fraction\n");
                else{
                    // printf("%c, %c", *(ans+0), *(ans+0+count[0]+1));
                    for(int i=negative; i<=count[0]; i++){
                        if(*(ans+i)=='/') {printf("proper fraction\n"); break;}
                        if(*(ans+i) > *(ans+i+count[0]+1)) {printf("improper fraction\n"); break;}
                        else if(*(ans+i) < *(ans+i+count[0]+1)){printf("proper fraction\n"); break;}
                        else if(i==count[0]) {printf("proper fraction\n"); break;}
                    }
                }
            }else if(var+integer==strlen(ans) && zero==0) printf("variable\n");
            else printf("erorr\n");
        }
    }
}
*/

#include <stdio.h>
#include <string.h>

int main(){
    int n;
    char ans[50];
    scanf("%d", &n);

    for(int j=0; j<n; j++){
        scanf("%s", ans);
        if(*ans=='0' && strlen(ans) == 0) printf("integer\n");
        else if(*ans=='-' && *(ans+1)=='0' && strlen(ans)==2) printf("error\n");
        else {
            int integer=0, fp=0, var=0, zero=0, fraction=0, para=0;
            for(int i=0; i<strlen(ans); i++){
                if(i==0 && *ans=='-') integer++;
                else if(i==0 && *ans=='0') {integer++; zero++;}
                else if(*(ans+i)>='0' && *(ans+i) <= '9') integer++;
                else if(*(ans+i) == '.' && i+1!=strlen(ans)) fp++;
                else if(*(ans+i) == '/') fraction++;
                else if(*(ans+i) == '(' && *(ans+i+1) != ')') para++;
                else if(*(ans+i) == ')' && i+1==strlen(ans)) para++;
                else if((*(ans+i)>='A' && *(ans+i) <= 'Z') || (*(ans+i)>='a' && *(ans+i) <= 'z') || *(ans+i) == '_') var++;
                // else
            }
            // printf("integer=%d, fp=%d, var=%d, zero=%d, fraction=%d, para=%d\n", integer, fp, var, zero, fraction, para);
            if(integer==strlen(ans) && zero==0) printf("integer\n");
            else if(integer+fp==strlen(ans) && zero==0){
                printf("float\n");
                for(int i=0; i<strlen(ans); i++) (*(ans+i)=='.')? printf("\n") : printf("%c", *(ans+i));
                printf("\n");
            } 
            else if(integer+var==strlen(ans) && zero==0) printf("variable\n");
            else if(para==2 && fraction==1) printf("algebraic fraction\n");
            else if(fraction==1){
                int count[2]={0};
                int negative = (*ans=='-')? 1: 0;
                int k=0;
                for(int i=negative; i<strlen(ans); i++){
                    if(*(ans+i) == '/'){k++; continue;}
                    count[k]++;
                }
                // printf("%d, %d, %d\n", negative, count[0], count[1]);
                if(count[0]<count[1]) printf("proper fraction\n");
                else if(count[0]>count[1]) printf("improper fraction\n");
                else{
                    for(int i=negative; i<=count[0]; i++){
                        // printf("%c, %c\n", *(ans+i), *(ans+i+count[0]+1));
                        if(*(ans+i) > *(ans+i+count[0]+1)) {printf("improper fraction\n"); break;}
                        else if(*(ans+i) < *(ans+i+count[0]+1)) {printf("proper fraction\n"); break;}
                    }
                }
            }else printf("error\n");
        }
    }
}