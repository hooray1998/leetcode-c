/*
 * @lc app=leetcode.cn id=149 lang=c
 *
 * [149] 直线上最多的点数
 * 
 * 思路: 依次把每个点作为基准点, 然后遍历其他的点, 统计各个斜率的点的个数, 注意点重合和斜率为0的情况
 */

// @lc code=start

typedef struct{
    double k;
    int count;
    UT_hash_handle hh;
}HashTable;

int maxPoints(int** points, int pointsSize, int* pointsColSize){

    int max = 0;
    HashTable *table = NULL, *tmp, *s;

    // 从每个点作为中心, 进行遍历, 统计每个点的各个斜率的情况
    for(int i=0;i<pointsSize;i++){
        // 初始化重合的点/y相同的点的个数
        int same = 1, sameY = 1;
        for(int j=i+1;j<pointsSize;j++){
            if(points[i][0] == points[j][0]) { // Y相同
                ++ sameY;
                if(points[i][1] == points[j][1]) { // X相同
                    ++ same;
                }
            } else {
                double dx = points[i][0] - points[j][0];
                double dy = points[i][1] - points[j][1];
                double k;
                /// FIXME: [[2,3],[3,3],[-5,3]] 正0.00和负0.00不相等, 所以在此进行适配
                if(dy==0){
                    k = 0;
                }else{
                    k = dy / dx;
                }
                HASH_FIND(hh, table, &k, sizeof(double), tmp);
                if (tmp == NULL){
                    tmp = malloc(sizeof(HashTable));
                    tmp->k = k;
                    tmp->count = 0;
                    HASH_ADD(hh, table, k, sizeof(double), tmp);
                }
                ++ tmp->count;
            }
        }


        HASH_ITER(hh, table, s, tmp){
            printf("i=%d: k,count = %f,%d\n", i, s->k, s->count);
            if(s->count + same > max){
                max = s->count + same;
            }
        }
        if (sameY > max){
            max = sameY;
        }
        printf("i=%d: size=%d\n", i, HASH_COUNT(table));


        HASH_CLEAR(hh, table);
        // table = NULL;
    }

    return max;

}
// @lc code=end

