#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node BTREE;

BTREE *mirror(BTREE *root){
    if(root == NULL || root->left == root->right){
        return;
    }
    else{
        struct node *temp = root->left;
        root->left = root->right;
        root->right = temp;
        root->left = mirror(root->left);
        root->right = mirror(root->right);
    }
    return root;
}