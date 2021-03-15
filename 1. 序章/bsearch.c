#include <stdio.h>
#include <string.h>

int *bound(int *start, int size, int key, int gt){
    int p, q, mid;
    p = 0;
    q = size-1;
    if(size==0){
        return NULL;
    }
    if(gt && key > start[size-1]){
        return NULL;
    }else if(!gt && key < start[0]){
        return NULL;
    }

    while(p<=q){
        mid = (p + q)/2;
        if(start[mid] == key){
            return start + mid;
        } else if(start[mid] < key){
            p = mid + 1;
        }else{
            q = mid - 1;
        }
    }

    // TODO: 为啥必须是q, 不能是p或者mid
    return start + q + gt;
}

int main()
{

    int b[] = {2, 4, 6, 8, 10};
    for (int i = -1; i < 12; i++)
    {
        int *find = bound(b, 5, /*key*/i, /*gt*/1);
        if(find){
            printf("find: %d >= %d\n", *find, i);
        }else{
            printf("find: NULL >= %d\n", i);
        }
    }
    
    for (int i = -1; i < 12; i++)
    {
        int *find = bound(b, 5, /*key*/i, /*gt*/0);
        if(find){
            printf("find: %d <= %d\n", *find, i);
        }else{
            printf("find: NULL <= %d\n", i);
        }
    }


    return 0;
}