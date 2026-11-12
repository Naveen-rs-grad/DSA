#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *prev;
    struct node *next;
} node;

typedef struct list
{
    node *head;
    node *tail;
} list;


void push_back(list **list, int value)
{
    node* new_node = malloc(sizeof(node));
    new_node->value = value;
    new_node->prev = (*list)->tail;
    new_node->next = NULL;
    if((*list)->tail == NULL)
    {
        (*list)->head = new_node;
    }
    else
    {
        (*list)->tail->next = new_node;
    }

    (*list)->tail = new_node;
}

void pop_back(list **list)
{
    if((*list)->tail == NULL)
    {
        printf("\nno element to delete!");
        return;
    }
    node *last_node = (*list)->tail;
    (*list)->tail = (*list)->tail->prev;
    if ((*list)->tail != NULL) (*list)->tail->next = NULL;
    else (*list)->head = NULL;
    free(last_node);
}

void print_list(list *list)
{
    printf("\n");
    for (node *current = list->head;
         current != NULL;
         current = current->next)
    {
        printf("%d ", current->value);
    }
}

int main()
{
    list data = {0};
    list *new = &data;
    push_back(&new, 10);
    push_back(&new, 20);
    push_back(&new, 30);
    push_back(&new, 30);
    push_back(&new, 40);

    print_list(new);

    pop_back(&new);
    pop_back(&new);

    print_list(new);

    return 0;
}