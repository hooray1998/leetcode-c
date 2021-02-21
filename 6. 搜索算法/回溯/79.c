#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*

给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false
 

提示：

board 和 word 中只包含大写和小写英文字母。
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3
*/
int direction[] = {-1, 0, 1, 0, -1};
bool backtracking(char** board, char *word, int row, int col, int x, int y, int count, bool **visit)
{
    if(visit[x][y]){
        return false;
    }
    visit[x][y] = true;
    if(count==strlen(word)){
        return true;
    }

    int newx, newy;
    for(int i=0;i<4;i++){
        newx = x + direction[i];
        newy = y + direction[i+1];
        // printf("%d,%d %s=>%c\n", newx, newy, word, word[count]);
        if(newx>=0&&newx<row&&newy>=0&&newy<col&&board[newx][newy] == word[count]){
            if(backtracking(board, word, row, col, newx, newy, count+1, visit)){
                return true;
            }
        }
    }
    visit[x][y] = false;
    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word)
{

    if(boardSize==0||boardColSize[0]==0||strcmp(word, "")==0) {
        return false;
    }

    int row = boardSize, col = boardColSize[0];
    int len=strlen(word);
    bool **visit = malloc(sizeof(bool *) * row);
    for(int i=0;i<row;i++){
        visit[i] = malloc(sizeof(bool) * col);
        memset(visit[i], 0, sizeof(bool) * col);
    }



    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(word[0]==board[i][j] && backtracking(board, word, row, col, i, j, 1, visit)){
                return true;
            }
        }
    }

    return false;
}

int main()
{
    char input[] = {
        'A','B','C','E',
        'S','F','C','S',
        'A','D','E','E'
    };
    int row = 3, col=(sizeof(input)/sizeof(char))/row;
    char *in[row];
    int colSize[row];
    for(int i=0;i<row;i++){
        in[i] = (char *)(input + i*col);
        colSize[i] = col;
    }

    printf("output:%d", exist(in, row, colSize, "DD"));
    return 0;
}