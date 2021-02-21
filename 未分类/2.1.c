#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int time;
    int deadline;
}Task;

int cmp(const void *arg1, const void *arg2)
{
    Task *a = (Task *)arg1;
    Task *b = (Task *)arg2;
    return b->deadline < a->deadline;
}

void Print(Task *task, int size)
{
    printf("value time dead\n");
    for(int i=0; i<size; i++) {
        printf("%5d %4d %4d\n", task[i].value, task[i].time, task[i].deadline);
    }
}

void PrintArr(int **arr, int taskSize, int taskDeadline)
{
    for(int i=0; i<taskSize; i++) {
        for(int j=0; j<taskDeadline; j++) {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    Task task[] = {
        {10, 6, 17},
        {6, 7, 13},
        {8, 3, 14},
        {2, 2, 5},
        {4, 4, 9},
        {12, 5, 20},
    };
    int taskSize = sizeof(task)/sizeof(task[0]);
    int arr[1001][1001] = {0};
    Print(task, 6);
    qsort(task, taskSize, sizeof(task[0]), cmp);
    Print(task, taskSize);

    for(int i=0; i<taskSize; i++) {
        for(int j=0; j<task[taskSize-1].deadline; j++) {
            arr[i][j] = 0;
        }
    }

    PrintArr(arr, taskSize, task[taskSize-1].deadline);
    for(int i=0; i<taskSize; i++) {
        for(int j=0; j<task[taskSize-1].deadline; j++) {
            arr[i][j] = 0;
        }
    }

    PrintArr(arr, taskSize, task[taskSize-1].deadline);
    return 0;
}
