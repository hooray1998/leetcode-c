#include <stdio.h>

typedef int HeapType;
#define MAX_HEAP_SIZE 1000;

HeapType heap[MAX_HEAP_SIZE + 1];
int heapSize = 0;

// 小顶堆
int cmp(const void *arg1, const void *arg2)
{
    HeapType *a = (HeapType *)arg1;
    HeapType *b = (HeapType *)arg2;
    return *a - *b;
}

void top()
{
    return heap[1];
}

void swap(HeapType *a, HeapType *b)
{
    HeapType *tmp = *a;
    *a = *b;
    *b = *tmp;
}

void swim(int pos)
{
    while(pos > 1 && cmp(heap + pos/2,  heap + pos) < 0){
        swap(heap + pos/2,  heap + pos);
        pos /= 2;
    }
}

void sink(int pos)
{
    int i;
    while(2 * pos <= heapSize){
        i = 2*pos;
        if(i<heapSize && cmp(heap + i, heap + i + 1) < 0){
            ++ i;
        }
        if(cmp(heap + i, heap + pos) < 0){
            swap(heap + i, heap + pos);
        }
        pos  = i;
    }

}

void push(HeapType *key)
{
    memcpy(&heap[heapSize+1], key, sizeof(HeapType));
    ++ heapSize;
}

void pop()
{
    heap[1] = heap[heapSize];
    -- heapSize;
    sink(1);
}


int main()
{
    int a[] = {49, 38, 64, 97, 76, 13, 29, 49};
    for (size_t i = 0; i < sizeof(a)/4; i++)
    {
        push(a + i);
    }

    


    
}
