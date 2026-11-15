/*
    Queue implementation using linked list
*/



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int value;
    struct node* next;
} node;

typedef struct queue
{   
    node *front;
    node *rear;
} queue;


void dequeue(queue *queue)
{
    //check if the queue is empty?
    if(queue->rear == NULL)
    {
        printf("\nQueue is empty, cannot dequeue");
        return;
    }

    //if not, go and remove the first inserted element which will be at the head
    node *node_to_delete = queue->front;
    queue->front = queue->front->next;

    /*Bug identified by AI - if front is null, potentiall the rear is also NULL*/
    if (queue->front == NULL)
        queue->rear = NULL;

    free(node_to_delete);
}


void enqueue(queue *queue, int value)
{
    node *new_node = malloc(sizeof(node));
    new_node->next = NULL;
    new_node->value = value;

    if(queue->front == NULL)
    {
        queue->front = new_node;
        queue->rear = new_node;
    }
    else
    {
        queue->rear->next = new_node;
        queue->rear = queue->rear->next;
    }
}

void print_queue(queue queue)
{
    printf("\n");
    while(queue.front!=NULL)
    {
        printf("%d ", queue.front->value);
        queue.front = queue.front->next;
    }
}

int main()
{
    queue queue;
    queue.front = NULL;
    queue.rear = NULL;

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);

    print_queue(queue);

    dequeue(&queue);
    dequeue(&queue);

    print_queue(queue);

    return 0;
}