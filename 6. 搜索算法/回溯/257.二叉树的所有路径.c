#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };
/*
 * @lc app=leetcode.cn id=257 lang=c
 *
 * [257] 二叉树的所有路径
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void backtracking(struct TreeNode *root, char **ret, int *returnSize, char *path)
{
    if(root->left == NULL && root->right == NULL){
        ret[*returnSize] = malloc(strlen(path) + 1);
        strcpy(ret[*returnSize], path);
        ++ *returnSize;
        printf("outptu:%s", path);
        return;
    }

    if(root->left){
        sprintf(path, "%s->%d", path, root->left->val);
        backtracking(root->left, ret, returnSize, path);
        *(strrchr(path, '>') -1) = 0;
    }
    if(root->right){
        sprintf(path, "%s->%d", path, root->right->val);
        backtracking(root->right, ret, returnSize, path);
        *(strrchr(path, '>') -1)= 0;
    }
}
char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if(root == NULL){
        return NULL;
    }

    char **ret = malloc(sizeof(char *) * 1001);
    char path[1000] = {0};
    sprintf(path, "%d", root->val);
    backtracking(root, ret, returnSize, path);

    return ret;
}
// @lc code=end

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

