#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define CAPACITY 10

typedef struct
{
    int data[CAPACITY];
    int front;
    int rear;
    int count;
} deque;

bool is_empty(deque deque)
{
    return deque.count == 0;
}

bool is_full(deque deque)
{
    return deque.count == CAPACITY-1;
}

void push_front(deque *deque, int value)
{
    // check if the queue is full
    if(is_full(*deque))
    {
        printf("\nQueue is full, push front failed!");
        return;
    }

    // if not full, put the node at front 
    deque->front = (deque->front-1 + CAPACITY)%CAPACITY; // adding capacity because, we don;t want to have the index negative
    deque->data[deque->front] = value;
    (deque->count)++;
}

void push_back(deque *deque, int value)
{
    // check if the queue is full
    if(is_full(*deque))
    {
        printf("\nQueue is full, push back failed!");
        return;
    }

    //if not full, put the node at back (rear)
    deque->data[deque->rear] = value; // rear points to next free slot and not the current last index, so we update first and then increase
    deque->rear =  (deque->rear + 1)%CAPACITY;
    (deque->count)++;
}

void pop_front(deque *deque)
{
    //check if queue is empty?
    if(is_empty(*deque))
    {
        printf("\nPopping not possible, queue is empty");
        return;
    }

    deque->front = (deque->front + 1)%CAPACITY;
    (deque->count)--;
    return;
}

void pop_back(deque *deque)
{
    //check if queue is empty?
    if(is_empty(*deque))
    {
        printf("\nPopping not possible, queue is empty");
        return;
    }

    deque->rear = (deque->rear - 1 + CAPACITY)%CAPACITY;
    (deque->count)--;
}

void print_deque(const deque *deque)
{
    printf("Front to back:");

    for (int i = 0; i < deque->count; i++) {
        int index = (deque->front + i) % CAPACITY;
        printf(" %d", deque->data[index]);
    }

    printf("\nfront=%d, rear=%d, count=%d\n",
           deque->front, deque->rear, deque->count);
}

int main()
{

    deque DQ = {0};

    push_back(&DQ, 10);
    push_back(&DQ, 20);
    push_back(&DQ, 30);

    push_front(&DQ, 40);

    push_back(&DQ, 50);

    print_deque(&DQ);


    return 0;
}