#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node BTREE;

int leafCount(BTREE *node){
    if(node == NULL){
        return 0;
    }
    else if(node->left == NULL && node->right == NULL){
        return 1;
    }
    else{
        return leafCount(node->left) + leafCount(node->right);
    }
}

BTREE *new_node(int data){
    BTREE *node = (BTREE*)malloc(sizeof(BTREE));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

BTREE *insert(BTREE *root, int data){
    if(root != NULL){
        if(data<root->data){
            root->left = insert(root->left, data);
        }
        else{
            root->right = insert(root->right, data);
        }
    }
    else{
        root = new_node(data);
        return root;
    }
}

int sumBTREE(BTREE *root){
    if(root == NULL)
        return 0;
    return(root->data + sumBTREE(root->left) + sumBTREE(root->right));
}

int findDepth(BTREE *root, int data){
    if(root == NULL){
        printf("There is no %d\n", data);
        return -10;
    }
    if(root->data = data){
        return 0;
    }
    else if(data< root->data){
        return 1 + findDepth(root->left, data);
    }
    else{
        return 1 + findDepth(root->right, data);
    }
}

int tree_height(BTREE *root){
    if(!root)
        return 0;
    else{
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if(left_height > right_height){
            return left_height + 1;
        }
        else{
            return right_height + 1;
        }
    }
}

int main(){
    BTREE *myroot = new_node(10);
    myroot = insert(myroot, 8);
    myroot = insert(myroot, 7);
    myroot = insert(myroot, 9);
    myroot = insert(myroot, 12);
    myroot = insert(myroot, 13);
    myroot = insert(myroot, 11);
    myroot = insert(myroot, 6);
    myroot = insert(myroot, 4);
    
    printf("Leaf count > %d\n", leafCount(myroot));
    printf("Sum of data > %d\n", sumBTREE(myroot));
    printf("Depth of given node > %d\n", findDepth(myroot, 10));
    int height = tree_height(myroot);
    
    printf("Height of tree > %d\n", height);

    return 0;
}