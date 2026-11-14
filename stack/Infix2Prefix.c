#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


#define STACK_CAPACITTY 128

/* ---------------------Basic stack operations functions ---------------------*/
typedef struct
{
    char data[STACK_CAPACITTY];
    int top;
} stack;

bool is_empty(stack *stack)
{
    return (*stack).top == -1;
}

bool is_full(stack *stack)
{
    return (*stack).top == STACK_CAPACITTY-1;
}


void pop(stack *stack)
{
    if(is_empty(stack))
    {
        printf("\nStack is empty cannot pop");
        return;
    }
    (*stack).top--;
}

char peek(stack *stack)
{
    if((*stack).top==-1)
    {
        printf("\nStack empty cannot peek");
        return '\0';
    }
    return (*stack).data[(*stack).top];
}

void push(stack *stack, char value)
{
    if(is_full(stack))
    {
        printf("\nStack is full!");
        return;
    }

    (*stack).top++;
    (*stack).data[(*stack).top] = value;
}

void print_stack(stack *stack)
{
    printf("\n");
    for(int i=(*stack).top;i>=0;i--)
    {
        printf("%d ", (*stack).data[i]);
    }
}

/* -------------- Infix to Prefix -------------------*/

int precedence(int op)
{
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

void infix_to_prefix(const char *infix, char *prefix)
{
    stack operand_stack;
    operand_stack.top = -1;

    char ans[STACK_CAPACITTY];
    size_t ans_length = 0;
    int stacked_op;

    for(size_t i = strlen(infix);i>0;i--) //size_t is unsigned
    {
        char token = infix[i - 1];
        if(isspace((unsigned char)token)) //space - then skip
        {
            continue;
        }
        else if(isalnum((unsigned char)token)) //alpha numerics - append to answer variable
        {
            ans[ans_length] = token;
            ans_length++;
        }
        else if(token == '(') // evaluate the paranethesis
        {
            while(!is_empty(&operand_stack) && peek(&operand_stack) != ')')
            {
                ans[ans_length] = peek(&operand_stack);
                ans_length++;
                pop(&operand_stack);
            }
            if (!is_empty(&operand_stack))
                pop(&operand_stack); // Remove the matching ')'
        }
        else if(token == ')')
        {
            push(&operand_stack, token);
        }
        else //Opeator are pushed to stack by evaluating the existing priority
        {
            int incoming_operator_precedence = precedence(token);

            while (!is_empty(&operand_stack) && peek(&operand_stack) != ')')
            {
                int last_operator_precedence_in_stack = precedence(peek(&operand_stack));

                bool should_pop = (last_operator_precedence_in_stack > incoming_operator_precedence) || (last_operator_precedence_in_stack == incoming_operator_precedence && token == '^');

                if (!should_pop) {
                    break;
                }

                ans[ans_length] = peek(&operand_stack);
                ans_length++;
                pop(&operand_stack);
            }
            
            push(&operand_stack, token);
        }

    }

    //now that we have evaluated all the operators, we will pop out and push to ans

    while(!is_empty(&operand_stack))
    {
        ans[ans_length] = peek(&operand_stack);
        ans_length++;
        pop(&operand_stack);
    }
    for (size_t i = 0; i < ans_length; ++i) {
        prefix[i] = ans[ans_length - 1 - i];
    }
    prefix[ans_length] = '\0';

}

int main()
{

    const char infix[] = "A+B*C";
    char prefix[STACK_CAPACITTY];

    infix_to_prefix(infix, prefix);

    printf("Infix:  %s\n", infix);
    printf("Prefix: %s\n", prefix);

    return 0;
}