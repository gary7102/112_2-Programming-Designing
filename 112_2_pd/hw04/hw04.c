#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef enum {
    INTEGER,
    FLOAT,
    VARIABLE,
    STRING
} TokenType;

TokenType getTokenType(char *input){
    int state = 0; // Initial state
    bool hasDecimal = false;

    int len = strlen(input);
    if(input[len-1] == '.'){
        return STRING;
    }

    for (int i = 0; i < strlen(input); ++i) {
        char ch = input[i];
        // printf("%d\n", state);
        switch (state) {
            case 0: // Initial state
                if (ch == '-' && i == 0) {
                    state = 1; // Move to negative integer state
                } else if (ch == '0') {
                    state = 2; // Move to integer zero state
                } else if (ch >= '1' && ch <= '9') {
                    state = 3; // Move to integer state
                } else if (ch == '_') {
                    state = 4; // Move to variable state
                } else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                    state = 4; // Move to variable state
                } else if (ch == '.') {
                    state = 5; // Move to float state
                    hasDecimal = true;
                } else {
                    state = 6; // Move to string state
                }
                break;
            case 1: // Integer state (with negative sign)
                if (ch >= '1' && ch <= '9') {
                    state = 1;
                }else if(ch == '0'){
                    if(strlen(input) == 2){ // if input = -0, then be string
                        state = 6;
                    }
                }else if(ch == '.'){
                    state = 5;
                    hasDecimal = true;
                }else {
                    state = 6; // Move to string state
                }
                break;
            case 2: // Integer zero state
                if(ch >= '0' && ch <= '9'){
                    state = 6;
                }else if(ch == '.'){
                    state = 5;
                    hasDecimal = true;
                }
                break;
            case 3: // Integer state
                if (ch >= '0' && ch <= '9') {
                    // Stay in the same state
                    continue;
                }else if(ch == '.'){
                    state = 5;
                    hasDecimal = true;
                } 
                else {
                    state = 6; // Move to string state
                }
                break;
            case 4: // Variable state
                if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '_') {
                    // Stay in the same state
                } else {
                    state = 6; // Move to string state
                }
                break;
            case 5: // Float state
                if (ch >= '0' && ch <= '9') {
                    // Stay in the same state
                    state = 5;
                } else if (ch == '.' && !hasDecimal) {
                    hasDecimal = true;
                } else {
                    state = 6; // Move to string state
                }
                break;
            default: // String state
                break;
        }
    }
    // Determine the token type based on the final state
    if (state == 1 || state == 2 || state == 3)
        return INTEGER;
    else if (state == 5)
        return FLOAT;
    else if (state == 4)
        return VARIABLE;
    else
        return STRING;
}

int main(){
    int N;
    scanf("%d", &N);
    getchar();

    for(int i=0; i<N; i++){
        char input[51];
        fgets(input, 51, stdin);

        // Remove newline character if present
        if (input[strlen(input) - 1] == '\n')
            input[strlen(input) - 1] = '\0';


        switch (getTokenType(input)){
            case INTEGER:
                printf("integer\n\n");
                break;
            case FLOAT:
                printf("float\n\n");
                break;
            case VARIABLE:
                if (strlen(input) > 10){
                    printf("string\n\n");
                }else{
                    printf("variable\n\n");
                }
                break;
            default :
                printf("string\n\n");
        }
    }    
}