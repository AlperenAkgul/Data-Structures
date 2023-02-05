#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node BTREE;

int level(BTREE *root, int x){
    if(root == NULL)
        return 0;
    if(x == 0)
        return 1;
    return level(root->left, x - 1) + level(root->right, x - 1);
}