#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    struct node *right;
    int data;
};

typedef struct node BTREE;

BTREE *new_node(int data){
    BTREE *p;
    p = (BTREE*)malloc(sizeof(struct node));
    p->data = data;
    p->left = p->right = NULL;
    return p;
}

BTREE *insert(BTREE *root, int x){
    if(root == NULL){
        root = new_node(x);
    }
    else{
        if(x > root->data){
           root->right = insert(root->right, x);
        }
        else if(x < root->data){
            root->left = insert(root->left, x);
        }
    }
    return root;
}

void inorder(BTREE *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(BTREE *root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(BTREE *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int leafCount(BTREE *root){
    if(root == NULL){
        return 0;
    }
    else if(root->left == NULL && root->right == NULL){
        return 1;
    }
    else{
        return leafCount(root->left)+leafCount(root->right);
    }
}

int size(BTREE *root){
    if(root != NULL){
        return (size(root->left) + 1 + size(root->right));
    }
}

int maxDepth(BTREE *root){
    int lDepth;
    int rDepth;
    if(root == NULL)
        return 0;
    else{
        lDepth = maxDepth(root->left);
        rDepth = maxDepth(root->right);

        if(lDepth > rDepth)
            return (lDepth + 1);
        else{
            return (rDepth + 1);
        }
    }
}

int find_depth(BTREE *root, int data){
    if(root == NULL){
        printf("There is no %d\n", data);
        return -100;
    }
    if(root->data==data){
        return 0;
    }
    else if(data < root->data){
        return 1 + find_depth(root->left, data);
    }
    else{
        return 1 + find_depth(root->right, data);
    }
}

int height(BTREE *root){
    if(root == NULL){
        return -1;
    }
    else{
        int left_height, right_height;
        left_height = height(root->left);
        right_height = height(root->right);

        if(right_height > left_height)
            return right_height + 1;
        else
            return left_height + 1;
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
    inorder(myroot);
    printf("\n");
    preorder(myroot);
    printf("\n");
    postorder(myroot);
    printf("\n");
    printf("Size: %d\n", size(myroot));
    printf("Max Depth: %d\n", maxDepth(myroot));
    printf("Leaf Count: %d\n", leafCount(myroot));
    printf("Depth 12: %d\n", find_depth(myroot, 12));
    printf("Height: %d\n", height(myroot));
    return 0;
}