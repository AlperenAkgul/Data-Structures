#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

typedef struct node AVLTREE;

AVLTREE *new_node(int data){
    AVLTREE *p = (AVLTREE*)malloc(sizeof(AVLTREE));
    p->data = data;
    p->left = p->right = NULL;
    p->height = 0;
}

int maxValue(int x, int y){
    return x>=y?x:y;
}

AVLTREE *leftRotate(AVLTREE *z){
    AVLTREE *temp = z->right;
    z->right = temp->left;
    temp->left = z;

    z->height = maxValue(z->left ==NULL?-1:z->left->height, z->right==NULL?-1:z->right->height) + 1;
    temp->height = maxValue(temp->left==NULL?-1:temp->left->height, temp->right==NULL?-1:temp->right->height) + 1;
    return temp;
}

AVLTREE *rightRotate(AVLTREE *z){
    AVLTREE *temp = z->left;
    z->left = temp->right;
    temp->right = z;

    z->height = maxValue(z->left ==NULL?-1:z->left->height, z->right==NULL?-1:z->right->height) + 1;
    temp->height = maxValue(temp->left==NULL?-1:temp->left->height, temp->right==NULL?-1:temp->right->height) + 1;
    return temp;
}

AVLTREE *leftRightRotate(AVLTREE *z){
    z->left = leftRotate(z->left);
    return rightRotate(z);
}

AVLTREE *rightLeftRotate(AVLTREE *z){
    z->right = rightRotate(z->right);
    return leftRotate(z);
}

AVLTREE *insertToAVL(int x, AVLTREE *tree){
    if(tree != NULL){
        if(x<tree->data)
            tree->left = insertToAVL(x, tree->left);
        else
            tree->right = insertToAVL(x, tree->right);

        tree->height = maxValue(tree->left==NULL?-1:tree->left->height, tree->right==NULL?-1:tree->right->height)+1;

        if((tree->left == NULL?-1:tree->left->height) - (tree->right == NULL?-1:tree->right->height) > 1 && x < tree->left->data)
            return  rightRotate(tree);

        if((tree->left == NULL?-1:tree->left->height) - (tree->right == NULL?-1:tree->right->height) > 1 && x > tree->left->data)
            return  leftRightRotate(tree);

        if((tree->left == NULL?-1:tree->left->height) - (tree->right == NULL?-1:tree->right->height) < -1 && x > tree->right->data)
            return  leftRotate(tree);
        
        if((tree->left == NULL?-1:tree->left->height) - (tree->right == NULL?-1:tree->right->height) < -1 && x < tree->right->data)
            return  rightLeftRotate(tree);
        }
        else{
        tree = new_node(x);
    }
    return tree;
}

void inorder(AVLTREE *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}

int main(){
    AVLTREE *myroot = NULL;
    int key;
    return 0;
}

