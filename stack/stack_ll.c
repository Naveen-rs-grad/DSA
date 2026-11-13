#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>

//The main thing here is the data is inserted at front and removed from front 

typedef struct node
{
    int value;
    struct node* next;
} node;

void push(node **stack_head, int value) //In prder to have stack operation we push the node at front
{
    node *new_node = malloc(sizeof(node));
    new_node->value = value;
    new_node->next = *stack_head;
    *stack_head = new_node;
}

void pop(node **stack_head) //To mimic stack operation stack from where we place which is at the front
{
    if(*stack_head == NULL)
    {
        printf("\nStack empty!");
        return;
    }

    node* delete = *stack_head;
    // if((*stack)->next == NULL)
    // {
    //     *stack == NULL;
    //     free(delete);
    //     return;
    // }

    (*stack_head) = (*stack_head)->next;
    free(delete);
    return;
}

void print_stack(node *stack)
{
    printf("\n");
    while(stack != NULL)
    {
        printf("%d ",stack->value);
        stack = stack->next;
    }
}


int main()
{
    node *stack = {0};

    push(&stack,10);
    push(&stack,20);
    push(&stack,30);
    push(&stack,40);
    push(&stack,50);

    print_stack(stack);

    pop(&stack);

    print_stack(stack);
    
    return 0;
}