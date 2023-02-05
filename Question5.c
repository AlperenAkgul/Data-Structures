#include <stdio.h>
#include <stdlib.h>

struct node{
    char name[15];
    char surname[15];
    double number;
    float final;
    struct node *left;
    struct node *right;
};
typedef struct node BTREE;

int total(BTREE *root){
    if(root == NULL){
        return 0;
    }
    else{
        return root->final + average(root->left) + average(root->right);
    }
}

int size(BTREE *root){
    if(root == NULL)    
        return 0;
    else    
        return 1 + size(root->left) + size(root->right);
}

void list(BTREE *root){
    int average = total(root) / size(root);
    if(root == NULL){
        return;
    }
    else{
        if(root->final > average)
            printf("%d\n%s %s", root->number, root->name, root->surname);
        list(root->left);
        list(root->right);
    }
}
