// #include <stdio.h>
// #include <string.h>

// int main(){
//     int count=0,co;
//     scanf("%d",&co);
//     while(count!=co){
//         char ans[50];
//         scanf("%s",ans);

//         if((*ans=='0' && strlen(ans)==1)) printf("integer\n");   // 0 return integer
//         else{
//             int point=0,ii=0,var=0,str=0,zero=0;
//             for(int u=0;u<strlen(ans);u++){
//                 if(u==0 && *ans=='-' && strlen(ans)>2){     // negative integer, but, -0 is not negative integer, so strlen(ans)>2 is needed.
//                     ii++;
//                 }
//                 else if(u==0 && *ans=='0'){     // integer 且 zero, but, 0123 is not inter so u==0 is needed. zero only >0 when first digit is 0.
//                     ii++;
//                     zero++;
//                 }
//                 else if(*(ans+u)>='0' && *(ans+u)<='9'){    // integer
//                     ii++;
//                 }
//                 else if(*(ans+u)=='.' && u+1!=strlen(ans)){     /// floating point, but, ex: 0. is string, therefore, u+1 != strlen(ans) is needed.
//                     point++;
//                 }
//                 else if(('A'<=*(ans+u) && *(ans+u)<='Z') || ('a'<=*(ans+u) && *(ans+u)<='z') || *(ans+u)=='_'){     //variable
//                     var++;
//                 }
//                 else{       //string
//                     str++;
//                 }
//             }

//             printf("\nfloating = %d, integer = %d, var = %d, string = %d, zero = %d\n",point,ii,var,str, zero);

//             if(ii==strlen(ans) && point==0 && zero==0){
//                 printf("integer\n");
//             }
//             else if((ii+point==strlen(ans)) && point==1){
//                 printf("float\n");
//             }                                              ///////////
//             else if(ii+var==strlen(ans) && strlen(ans)<=10 && zero==0){// && ((*ans<='Z' && *ans>='A') || (*ans<='z' && *ans>='a') || *ans=='_')
//                 printf("variable\n");                      ///////////
//             }
//             else{
//                 printf("string\n");
//             }
//         }

//         count++;
//     }
// }


#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int j=0; j<n; j++){
        char ans[50];
        scanf("%s", ans);

        if(strlen(ans) == 1 && *ans == '0') printf("integer\n"); // 0 return integer.
        else if(*ans == '-' && *(ans+1) == '0') printf("string\n");     //-0 return string
        else{
            int integer=0, fp=0, var=0, str=0, zero =0;
            for(int i=0; i<strlen(ans); i++){
                if(i == 0 && *ans == '-') integer++;        // first char is '-', then maybe negative integer
                else if(i==0 && *ans =='0'){ integer++; zero++;}    // first char is '0' then maybe float or string
                else if(*(ans+i) >= '0' && *(ans+i) <='9') integer++;   // integer
                else if(*(ans+i) == '.' && i+1!=strlen(ans)) fp++;      // float, but 0. or 1. is not float, so i+1 != strlen(ans) is needed
                else if((*(ans+i) >= 'A' && *(ans+i) <= 'Z') || (*(ans+i) >= 'a' && *(ans+i) <= 'z') || (*(ans+i) =='_')) var++;    // var
                else str++; //string
            }
            printf("integer = %d, fp = %d, var = %d, str = %d, zero = %d\n", integer, fp, var, str, zero);

            if(integer == strlen(ans) && fp==0 && zero ==0 && var == 0) printf("integer\n");    
            else if(integer+fp == strlen(ans) && fp == 1) printf("float\n");    // if 1.1. then fp!=1 then it is not fp.
            else if(var+integer == strlen(ans) && strlen(ans) <= 10 && zero==0) printf("variable\n");
            else printf("string\n");
        }
    }
}

/*
if 0 return integer.
else if -0 return string.
else:
    negative integer return integer.
    zero 且 integer, but 0123 is not integer so i==0 is needed, zero only appears in first char is '0'.
    integer 
    fp 
    var
    str

*/
