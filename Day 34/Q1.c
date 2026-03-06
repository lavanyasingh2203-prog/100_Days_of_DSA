#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    
    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    
    return value;
}

int main() {
    char exp[100];
    int i = 0;
    
    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    while (exp[i] != '\0') {
        
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        }
        
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            
            int op2 = pop();
            int op1 = pop();
            int result;

            switch (exp[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }

            push(result);
        }

        i++;
    }

    printf("Result = %d\n", pop());

    return 0;
}