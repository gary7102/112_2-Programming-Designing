#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int coeff;
    int exp;
    struct node* next;
} Node;

Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void appendNode(Node** poly, int coeff, int exp) {
    // if (coeff == 0) return; // If coefficient is zero, we don't need to add the term

    Node* newNode = createNode(coeff, exp);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        Node* temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        // printf("poly1.exp = %d, coeff = %d\n", poly1->exp, poly1->coeff);
        // printf("poly2.exp = %d, coeff = %d\n", poly2->exp, poly2->coeff);

        if (poly1->exp > poly2->exp) {
            appendNode(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            appendNode(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            appendNode(&result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        appendNode(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        appendNode(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }
    return result;
}

Node* subtractPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            appendNode(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            appendNode(&result, -poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            appendNode(&result, poly1->coeff - poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        appendNode(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        appendNode(&result, -poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }
    return result;
}

Node* multiplyPolynomials(Node* poly1, Node* poly2) {
    if (poly1 == NULL || poly2 == NULL) {
        return NULL;
    }

    Node* result = NULL;
    for (Node* ptr1 = poly1; ptr1 != NULL; ptr1 = ptr1->next) {
        Node* temp = NULL;
        for (Node* ptr2 = poly2; ptr2 != NULL; ptr2 = ptr2->next) {
            appendNode(&temp, ptr1->coeff * ptr2->coeff, ptr1->exp + ptr2->exp);
        }
        result = addPolynomials(result, temp);
    }
    return result;
}

int checkzero(Node* poly){
    while(poly != NULL){
        if(poly->coeff!=0) return 0;
        poly = poly->next;
    }
    return 1;
}

void printPolynomial(Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }else if(checkzero(poly)){
        printf("0\n");
        return;
    }

    Node* temp = poly;
    int isFirst = 1;
    while (temp != NULL) {
        if (temp->coeff != 0) {
            if (temp->coeff > 0 && !isFirst) {
                printf("+");
            } else if (temp->coeff < 0) {
                printf("-");
            }
            if (temp->exp == 0) {
                printf("%d", abs(temp->coeff));
            } else if (temp->exp == 1) {
                if (abs(temp->coeff) != 1) {
                    printf("%dx", abs(temp->coeff));
                } else {
                    printf("x");
                }
            } else {
                if (abs(temp->coeff) != 1) {
                    printf("%dx^%d", abs(temp->coeff), temp->exp);
                } else {
                    printf("x^%d", temp->exp);
                }
            }
            isFirst = 0;
        }
        temp = temp->next;
    }
    printf("\n");
}

Node* readPolynomial() {
    Node* poly = NULL;
    char buffer[1024];
    char tempBuffer[1024];
    fgets(buffer, 1024, stdin);
    for(int i=0; i<sizeof(buffer); i++) tempBuffer[i] = buffer[i];

    char* token = strtok(buffer, " ");
    int coeff, exp = 0;

    // Count the number of coefficients to determine the highest exponent
    int count = 0;
    char* tempToken = token;
    while (tempToken != NULL) {
        count++;
        tempToken = strtok(NULL, " ");
    }

    exp = count - 1;
    token = strtok(tempBuffer, " ");
    while (token != NULL) {
        sscanf(token, "%d", &coeff);
        appendNode(&poly, coeff, exp);
        exp--;
        token = strtok(NULL, " ");
    }

    return poly;
}

int main() {
    Node* poly1 = readPolynomial();
    Node* poly2 = readPolynomial();

    Node* sum = addPolynomials(poly1, poly2);
    Node* difference = subtractPolynomials(poly1, poly2);
    Node* product = multiplyPolynomials(poly1, poly2);
    
    printPolynomial(sum);
    printPolynomial(difference);
    printPolynomial(product);

    return 0;
}