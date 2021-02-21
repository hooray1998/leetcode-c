/*
 * @lc app=leetcode.cn id=130 lang=c
 *
 * [130] 被围绕的区域
 */

// @lc code=start


/*
从四周找所有跟边缘相连的O, 其他的都是被包围的
*/
int direction[] = {-1, 0, 1, 0, -1};
void dfs(char **board, int row, int col, int x, int y)
{
    if(board[x][y] != 'O'){
        return;
    }

    board[x][y] = 'A';
    int newx, newy;
    for(int i=0;i<4;i++){
        newx = x + direction[i];
        newy = y + direction[i+1];
        if(newx>=0&&newx<row&&newy>=0&&newy<col){
            dfs(board, row, col, newx, newy);
        }
    }
}

void solve(char** board, int boardSize, int* boardColSize){
    if(boardSize == 0) return;
    int row=boardSize, col = boardColSize[0];
    for(int i=0;i<row;i++){
        dfs(board, row, col, i, 0);
        dfs(board, row, col, i, col-1);
    }
    for(int i=0;i<col;i++){
        dfs(board, row, col, 0, i);
        dfs(board, row, col, row-1, i);
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(board[i][j] == 'A'){
                board[i][j] = 'O';
            }else{
                board[i][j] = 'X';
            }
        }
    }

}
// @lc code=end

