#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>

#define STACK_CAPACITY 5

typedef struct
{
    int data[STACK_CAPACITY];
    int top;
} stack;

bool is_stack_full(stack stack)
{
    return stack.top == STACK_CAPACITY-1;
}

bool is_stack_empty(stack stack)
{
    return stack.top == -1;
}

void push_back(stack *stack, int value)
{
    if(is_stack_full(*stack))
    {
        printf("\nstack full!");
        return;
    }

    stack->top++;
    stack->data[stack->top] = value;
}

void pop(stack* stack)
{
    if(is_stack_empty(*stack))
    {
        printf("\nStack is empty!");
        return;
    }
    (stack->top)--;
}

void print_stack(stack stack)
{
    int i=0;
    printf("\n");
    while(i<=stack.top)
    {
        printf("%d ", stack.data[i]);
        i++;
    }
}

int main()
{

    stack new_stack;
    new_stack.top = -1;

    push_back(&new_stack, 10);
    push_back(&new_stack, 20);
    push_back(&new_stack, 30);
    push_back(&new_stack, 40);

    print_stack(new_stack);

    pop(&new_stack);
    pop(&new_stack);

    print_stack(new_stack);
    
    pop(&new_stack);
    pop(&new_stack);
    pop(&new_stack);
    pop(&new_stack);

    print_stack(new_stack);

    return 0;
}

//  gcc .\stack.c -o stk.exe 