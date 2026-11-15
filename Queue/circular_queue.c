/*
    Circular queue implementation using an array
*/



#include <stdio.h>


#define QUEUE_CAPACITY 10


/* front is the next item to remove; rear is the next slot to fill. */
typedef struct
{
    int data[QUEUE_CAPACITY];
    int front;
    int rear;
    int count;
} CircularQueue;

void enqueue(CircularQueue *Cqueue, int value)
{
    // check if its full?
    if(Cqueue->count == QUEUE_CAPACITY)
    {
        printf("Queue is full, cannot enqueue\n");
        return;
    }

    // if not, push at the rear

    Cqueue->data[Cqueue->rear] = value;
    Cqueue->rear = (Cqueue->rear + 1) % QUEUE_CAPACITY;
    (Cqueue->count)++;

}

void dequeue(CircularQueue *Cqueue)
{
    // check if queue is empty
    if(Cqueue->count == 0)
    {
        printf("Queue is empty, cannot dequeue\n");
        return;
    }

    // Remove the first item by advancing front.
    Cqueue->front = (Cqueue->front + 1)%QUEUE_CAPACITY;
    (Cqueue->count)--;

}

void print_queue(const CircularQueue *Cqueue)
{
    if (Cqueue->count == 0)
    {
        printf("Queue is empty\n");
        return;
    }

    for (int i = 0; i < Cqueue->count; i++)
    {
        int index = (Cqueue->front + i) % QUEUE_CAPACITY;
        printf("%d ", Cqueue->data[index]);
    }
    printf("\n");
}

int main(void)
{
    CircularQueue Cqueue = {0};

    // Fill the queue.
    for (int value = 10; value <= 100; value += 10)
    {
        enqueue(&Cqueue, value);
    }
    print_queue(&Cqueue);

    dequeue(&Cqueue);
    dequeue(&Cqueue);

    // Reuse the two slots at the beginning of the array.
    enqueue(&Cqueue, 110);
    enqueue(&Cqueue, 120);
    print_queue(&Cqueue);

    return 0;
}
