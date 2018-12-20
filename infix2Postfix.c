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
    struct Stack *stack = (struct Stack*) malloc(sizeof(struck Stack));
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
int operatorPres(char sth) {
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
            printf("%c", infix[i]);                
        return 0;
        }

        else if(infix[i] == '(')
            push(stack, infix[i]);

        else if(infix[i] == '(') {
            while(!(isEmpty)) {
                //TODO find somewhere to pop it to :D
                =pop(stack);
            }
        }

    }



}

int main() {

    return 0;
}
