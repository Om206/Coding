#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Queue
{
    int array[MAX_SIZE];
    int front;
    int rear;
};

struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(struct Queue *q)
{
    if (q->front == -1 && -1 == q->rear)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Queue *q)
{
    if ((q->rear + 1) % MAX_SIZE == q->front)
    {
        return 1;
    }
    return 0;
}

void Enqueue(struct Queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue is FUll\n");
        return;
    }

    if (isEmpty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->array[q->rear] = data;
    return;
}

int Dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is already empty");
        return -1;
    }
    int data = q->array[q->front];
    if (q->rear == q->front)
    {
        q->rear = q->front = -1;
    }
    else
    {
        q->front++;
    }
    return data;
}

int main()
{
    struct Queue *queue = createQueue();

    for (int i = 0; i < 5; i++)
    {
        Enqueue(queue, i);
    }

    printf("The element removed is %d\n", Dequeue(queue));
    Enqueue(queue, 100);
    printf("The element at front is %d\n", queue->array[queue->front]);
    printf("The element at front rear %d\n", queue->array[queue->rear]);
    return 0;
}