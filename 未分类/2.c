#include <stdio.h>


// 获取剩余时间最少的窗口
int getmin(int *pipe)
{
    int min;
    min = (pipe[0] <= pipe[1])? 0:1;
    min = (pipe[min] <= pipe[2])? min:2;
    min = (pipe[min] <= pipe[3])? min:3;
    return min;
}

int main()
{
    int time[5] = {0, 5, 10, 15, 20};
    int people[256] = {1, 2, 2, 2, 1};
    int size = 5;
    int pipe[2][4] = {0};
    int pipeNum = 4;
    int output[256] = {0};
    int outputSize = 0;
    int min;
    int cur=0;

    min = getmin(pipe[0]);
    while(cur<size || pipe[0][min] <= 20) {
        if(cur<size){
            if(pipe[0][min] == 0) { // 有空余的流水线 并且有人在等待
                pipe[0][min] = time[people[cur]];
                pipe[1][min] = ++cur;
            }else{
                //输出id, 更新时间
                output[outputSize++] = pipe[1][min];
                pipe[0][0] -= pipe[0][min];
                pipe[0][1] -= pipe[0][min];
                pipe[0][2] -= pipe[0][min];
                pipe[0][3] -= pipe[0][min];
            }
        } else {
            if(pipe[0][min] == 0) { // 有空余的流水线 并且有人在等待
                pipe[0][min] = 888;
            }else{
                output[outputSize++] = pipe[1][min];
                pipe[0][min] = 888;
            }
        }

        for(int i=0; i<4;i++) {
            printf("[%d]=%d, id=%d\n", i, pipe[0][i], pipe[1][i]);
        }
        for(int i=0;i<outputSize;i++) {
            printf("output=%d \n", output[i]);
        }
        min = getmin(pipe[0]);
    }


    return 0;
}