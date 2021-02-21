#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QUEUE_MAX_SIZE 10000
typedef struct {
    int x;
    int y;
}QueueData;

typedef struct {
    QueueData data[QUEUE_MAX_SIZE];
    int front;
    int back;
}Queue;

void InitQueue(Queue *queue)
{
    queue->front = queue->back = 0;
}

void EnQueue(Queue *queue, int x, int y)
{
    queue->data[queue->back].x = x;
    queue->data[queue->back].y = y;
    queue->back = (queue->back + 1) % QUEUE_MAX_SIZE;
}

void DeQueue(Queue *queue, QueueData *data)
{
    data->x = queue->data[queue->front].x;
    data->y = queue->data[queue->front].y;
    queue->front = (queue->front + 1) % QUEUE_MAX_SIZE;
}

int GetQueueSize(Queue *queue)
{
    return (queue->back - queue->front + QUEUE_MAX_SIZE) % QUEUE_MAX_SIZE;
}