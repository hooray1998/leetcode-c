// 0:38
#include <stdio.h>

int getroot(int *root, int a)
{
    while (root[a] != a) {
        a = root[a];
    }
    return a;
}

int main()
{
    int root[200] = {0};
    int input[5][5] = {
        {1, 1, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1},
    };
    int size = 5;
    int unionSize = 0;
    int rooti, rootj;
    for(int i=0; i<size; i++) {
        root[i] = i;
    }
    for(int i=0; i<size; i++) {
        for(int j=i+1; j<size; j++) {
            if(input[i][j] == 1) {
                rooti = getroot(root, i);
                rootj = getroot(root, j);
                if (rooti != rootj) {
                    root[rooti] = rootj;
                    ++ unionSize;
                }
            }
        }
    }
    printf("%d", size - unionSize);
    return 0;
}