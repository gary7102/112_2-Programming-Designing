#include <stdio.h>

typedef int (*GateOperation)(int, int);

typedef struct {
    int input1;
    int input2;
    int output;
    GateOperation operation;  // Pointer to the function that performs the gate operation
} LogicGate;

int andGate(int input1, int input2) {return input1 && input2;}

int orGate(int input1, int input2) {return input1 || input2;}

int notGate(int input1, int input2) {return !input1;}

int bufferGate(int input1, int input2) {return input1;} 

void setupGate(LogicGate *gate, char type, int input1, int input2) {
    gate->input1 = input1;
    gate->input2 = input2;
    switch (type) {
        case 'A':
            gate->operation = andGate;
            break;
        case 'O':
            gate->operation = orGate;
            break;
        case 'N':
            gate->operation = notGate;
            break;
        case 'B':
            gate->operation = bufferGate;
            break;
        // default:
        //     printf("Invalid gate type\n");
    }
}

int main() {
    int X1, X2, X3;
    char PG, QG, RG;

    scanf("%d %d %d", &X1, &X2, &X3);
    scanf(" %c %c %c", &PG, &QG, &RG);

    LogicGate P, Q, R;
    setupGate(&P, PG, X1, 0);
    setupGate(&Q, QG, X2, P.operation(P.input1, P.input2));
    setupGate(&R, RG, X3, Q.operation(Q.input1, Q.input2));

    int Y1 = P.operation(P.input1, P.input2);
    int Y2 = Q.operation(Q.input1, Q.input2);
    int Y3 = R.operation(R.input1, R.input2);

    printf("%d %d %d\n", Y1, Y2, Y3);

    return 0;
}
