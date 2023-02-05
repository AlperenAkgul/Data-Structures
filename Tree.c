#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *left;
    struct node *right;
    int data;
};

typedef struct node BTREE;

BTREE *createLeaf(BTREE *root, int x){
    BTREE *leaf = (BTREE*)malloc(sizeof(struct node));
    leaf->data = x;
    leaf->left = leaf->right = NULL;
    return leaf;
}

BTREE *insert(BTREE *root, int x){
    if(root == NULL){
        root = createLeaf(root, x);
    }
    else{
        if(x < root->data){
            root->left = insert(root->left, x);
        }
        else{
            root->right = insert(root->right, x);
        }
    }
    return root;
}

void print(BTREE *root){
    if(root == NULL){
        return;
    }
    else{
        print(root->left);
        printf("%d\t", root->data);
        print(root->right);
    }
}

int leafCount(BTREE *root){ //leaves on tree
    if(root == NULL){
        return 0;
    }
    else if(root->left == root->right){
        return 1;
    }
    else{
        return leafCount(root->left) + leafCount(root->right);
    }
}

int goToLeft(BTREE *root){
    if(root == NULL){
        return 0;
    }
    else{
        return 1 + goToLeft(root->left);
    }
}

int goToRight(BTREE *root){
    if(root == NULL){
        return 0;
    }
    else{
        return 1 + goToRight(root->right);
    }
}


int height(BTREE *root, int data){ //height of a node
    if(root->data == data){
        int leftHeight = goToLeft(root->left);
        int rightHeight = goToRight(root->right);
        if(leftHeight > rightHeight){
            return leftHeight;
        }
        else{
            return rightHeight;
        }
    }
    else{
        if(data < root->data){
            return height(root->left, data);
        }
        else{
            return height(root->right, data);
        }
    }
}


int heightOfTree(BTREE *root){
    if(root == NULL){
        return -1;
    }
    else{
        int leftHeight = 0;
        int rightHeight = 0;
        leftHeight = 1 + heightOfTree(root->left);
        rightHeight = 1 + heightOfTree(root->right);

        if(leftHeight > rightHeight){
            return leftHeight;
        }
        else{
            return rightHeight;
        }
    }
}

int depth(BTREE *root, int data){
    if(data == root->data){
        return 0;
    }
    else{
        if(data < root->data){
            return 1 + depth(root->left, data);
        }
        else{
            return 1 + depth(root->right, data);
        }
    }
}

int maxDepth(BTREE *root){
    if(root == NULL){
        return -1;
    }
    else{
        int leftDepth = maxDepth(root->left) + 1;
        int rightDepth = maxDepth(root->right) + 1;
        if(leftDepth > rightDepth){
            return leftDepth;
        }
        else{
            return rightDepth;
        }
    }
}

int main(){
    BTREE *root = NULL;
    int data;
    printf("Enter data ");
    scanf("%d", &data);
    while(data != -1){
        root = insert(root, data);
        printf("Enter data ");
        scanf("%d", &data);
    }
    print(root);

    printf("\nHeight of 8 is %d", height(root, 8));
    printf("\nHeight of tree is %d", heightOfTree(root));
    printf("\nLeaf Count is %d", leafCount(root));
    printf("\nDepth of 6 is %d", depth(root, 6));
    printf("\nMaximum Depth of tree is %d", maxDepth(root));

    return 0;
}