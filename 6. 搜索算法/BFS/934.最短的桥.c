/*
 * @lc app=leetcode.cn id=934 lang=c
 *
 * [934] 最短的桥
 */

// @lc code=start
#define QUEUE_MAX_SIZE 10000
int direction[] = {-1, 0, 1, 0, -1};
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

void dfs(int **A, int row, int col, int x, int y, Queue *queue)
{
    int newx, newy;
    A[x][y] = 2;
    EnQueue(queue, x, y);

    for(int i=0;i<4;i++){
        newx = x + direction[i];
        newy = y + direction[i+1];
        if(newx>=0&&newx<row&&newy>=0&&newy<col&&A[newx][newy]==1){
            dfs(A, row, col, newx, newy, queue);
        }
    }
}


int shortestBridge(int** A, int ASize, int* AColSize){
    // 一定有两个岛, 所以不用判断为空
    int row = ASize, col = AColSize[0];
    bool change = false;
    Queue queue;
    InitQueue(&queue);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(A[i][j]){
                dfs(A, row, col, i, j, &queue);
                change = true;
                break;
            }
        }
        if(change){
            break;
        }
    }

    int newx, newy;
    QueueData pos;
    int step = 0;
    int size;
    while(size = GetQueueSize(&queue)){
        for(int i=0;i<size;i++){
            DeQueue(&queue, &pos);
            for(int i=0;i<4;i++){
                newx = pos.x + direction[i];
                newy = pos.y + direction[i+1];
                if(newx>=0&&newx<row&&newy>=0&&newy<col){
                    if(A[newx][newy]==0){
                        A[newx][newy]=2;
                        EnQueue(&queue, newx, newy);
                    } else if(A[newx][newy]==1){
                        return step;
                    }
                }
            }
        }
        ++ step;
    }

    // for(int i=0;i<row;i++){
    //     for(int j=0;j<col;j++){
    //         printf("%d ", A[i][j]);
    //     }
    //     printf("\n");
    // }
    return step;
}
// @lc code=end

