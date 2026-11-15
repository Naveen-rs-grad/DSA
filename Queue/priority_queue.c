#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


#define CAPACITY 5

typedef struct
{
    int value;
    int priority;
} item;



//Here the front and rear not needed as we are using simple unsorted array
typedef struct 
{
    item data[CAPACITY];
    int count;
} PriorityQueue;

void enqueue(PriorityQueue *queue, int value, int pri)
{
    //check if queue is full
    if((*queue).count == CAPACITY-1)
    {
        printf("\nQueue if full , cannot push element");
        return;
    }

    //if not go and put at the back
    queue->data[queue->count].value = value;
    queue->data[queue->count].priority = pri;
    (queue->count)++;
}

void dequeue(PriorityQueue *queue)
{
    // check if queue is empty
    if(queue->count == 0)
    {
        printf("\nQueue is empty, cannot perform dequeue");
        return;
    }
    
    // if not empty, go ahead and check for the highest priority (pri number is less)
    int highest_priority_index = 0;
    for(int i=1;i<queue->count;i++)
    {
        if(queue->data[i].priority < queue->data[highest_priority_index].priority)
        {
            highest_priority_index = i;
        }
    }

    // once found delete it by pushing the element at the left

    for(int i = highest_priority_index;i<queue->count - 1;i++)
    {
        queue->data[i] = queue->data[i+1]; 
    }

    (queue->count)--;
    return;

}

void print_queue(PriorityQueue queue)
{
    printf("\n");
    for(int i=0;i<queue.count;i++)
    {
        printf("%d %d .. ", queue.data[i].value, queue.data[i].priority);
    }
}


int main()
{
    PriorityQueue Queue;
    Queue.count = 0;
    enqueue(&Queue, 10, 2);
    enqueue(&Queue, 20, 1);
    enqueue(&Queue, 30, 1);

    print_queue(Queue);

    dequeue(&Queue);
    print_queue(Queue);

    dequeue(&Queue);
    print_queue(Queue);

    return 0;
}