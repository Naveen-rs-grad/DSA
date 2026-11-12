#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
} node;


void push_back(node **tail, int value)
{
    node* new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    new_node->value = value;

    if(*tail == NULL)
    {
        new_node->next = new_node; //first node points to itself
    }
    else
    {
        new_node->next = (*tail)->next; // point to head
        (*tail)->next = new_node; //old tail points to new node
    }

    *tail = new_node; //now new node is the tail
}

void pop_front(node **tail)
{
    if (*tail == NULL) return;

    node *head = (*tail)->next;
    if (head == *tail)
    {
        *tail = NULL; // removing the only node leaves an empty list
    }
    else
    {
        (*tail)->next = head->next; // tail now points to the next head
    }
    free(head);
}

void print_list(node *tail)
{
    if (tail == NULL) return;

    node* current = tail->next; //stores head

    do
    {
        printf("%d ", current->value);
        current = current->next;
    } while (tail->next != current);
    printf("\n");
}


int main()
{
    node* new_list = NULL;

    push_back(&new_list, 10);
    push_back(&new_list, 20);
    push_back(&new_list, 30);
    push_back(&new_list, 40);
    push_back(&new_list, 50);

    print_list(new_list);
    pop_front(&new_list);
    print_list(new_list);

    while (new_list != NULL)
    {
        pop_front(&new_list);
    }
    return 0;
}
