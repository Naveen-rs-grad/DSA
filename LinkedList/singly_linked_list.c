#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
} node;

void push_front(node **head, int value)
{
    node *new_node = malloc(sizeof(node));
    new_node ->value = value;
    new_node-> next = *head;
    *head = new_node;
}

void push_back(node **head, int value)
{
    node *traverser = *head;
    node *temp_node = malloc(sizeof(node));

    temp_node->value = value;
    temp_node->next = NULL;
    
    if(*head==NULL)
    {
        *head = temp_node;
        return;
    }

    while(traverser->next != NULL)
    {
        traverser = (*traverser).next;
    }
    
    traverser->next = temp_node;
}

void push_atindex(node **head,int index, int value)
{
    int current_index = 0;
    node *current = *head;
    if(index < 0)
    {
        printf("\nNegative index");
        return;
    }
    if(index == 0)
    {
        push_front(head, value);
        return;
    }
    while((current)!=NULL)
    {
        if(current_index == index-1)
        {
            if((current)->next == NULL)
            {
                push_back(&current, value);
                return;
            }
            node *new_node = malloc(sizeof(node));
            if (new_node == NULL) {
                printf("\nMem Allocation failed in push_atindex");
                return;
            }
            new_node->next = (current)->next;
            new_node->value = value;
            (*current).next = new_node;
            return;
        }
        current = current->next;
        current_index++;
    }
    printf("\nindex error! index out of bound!");
}

void pop_front(node **head)
{
    if(*head == NULL) return ;
    node* temp_node = *head;
    *head = (*head)->next;
    free(temp_node);
}

void pop_back(node **head)
{
    if(*head==NULL)
    {
        return;
    }

    node* temp_node = *head;

    if((**head).next == NULL)
    {
        *head = NULL;
        free(temp_node);
        return;
    }

    while((*temp_node).next->next!=NULL)
    {
        temp_node = temp_node->next;
    }
    node *last_node = temp_node->next;
    temp_node->next = NULL;
    free(last_node);
}

void print_list(node *head)
{
    printf("\n");
    while(head!=NULL)
    {
        printf("%d ", ((*head).value));
        head = head->next;
    }
    // printf("\n");
}

int main()
{
    node *head= NULL;
    push_front(&head, 10);
    push_front(&head, 20);
    push_front(&head, 30);
    push_front(&head, 40);
    push_back(&head, 50);

    print_list(head);

    pop_back(&head);
    print_list(head);

    push_atindex(&head, 3, 99);
    print_list(head);

    return 0;
}