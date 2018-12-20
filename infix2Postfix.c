#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxString 250

struct Stack {
    int top;
    int size;
    int *array;
};

//
//Stack Operations
//

struct Stack *makeStack(int size) {
    struct Stack *stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1; //Empty stack
    stack->size = size;
    stack->array = (int *) malloc(sizeof(int)*stack->size);
    return stack;
}


//Checks if the stack is full
bool isFull(struct Stack *stack) {
    if(stack->size-1 == stack->top)
        return true;
    else
        return false;
}

//Checks if the stack is empty
bool isEmpty(struct Stack *stack) {
    if(stack->top == -1)
        return true;
    else
        return false;   
}

//If the stack is not full, puts the given element into the stack.
bool push(struct Stack *stack, int data) {
    if(isFull(stack))
        return false;
    stack->top++;
    stack->array[stack->top] = data;
    return true;
}

//If the stack is not empty, pops the top off of the stack.
int pop(struct Stack *stack) {
    if(isEmpty(stack))
        return -1;
    int popd = stack->top;
    stack->top = stack->top-1;
    return popd;
}

//
//Evaluation Operations
//
int operatorPrec(char sth) {
    if(sth=='+' || sth=='-')
        return 1;
    if(sth=='*' || sth=='/')
        return 2;
    if(sth=='^')
        return 3;
}

//Returns true if the character is a digit representation.
int isOperand(char sth) {
    return(sth >= '0' && sth <= '9');
}

//The whole thing!
int infix2Postfix(char * infix) {
    struct Stack *stack = makeStack(strlen(infix));
    int i;

    for(i=0; i<strlen(infix); i++) {
        if(isOperand(infix[i])) {
            printf("%c ", infix[i]);                
        return 0;
        }

        else if(infix[i] == '(')
            push(stack, infix[i]);

        else if(infix[i] == ')') {
            while((stack->top!='(')) {
                printf("%c ", pop(stack));
            }
            printf("%c", pop(stack));
        }
        else {
            while(!isEmpty(stack) && (operatorPrec(stack->top) >= operatorPrec(infix[i]))) {
                printf("%c", pop(stack));        
        }
            push(stack, infix[i]);

        }
    
    while(!isEmpty(stack)) {
        printf("%c", pop(stack)); //Prints the "leftover" operators in the stack.
    }

    }


}

int main() {
    char *infix;
    printf("Write an infix expression using no spaces.");
    scanf("%c", infix);
    infix2Postfix(infix);

    return 0;
}
