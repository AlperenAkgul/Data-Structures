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

/*AVLTREE *delete(AVLTREE *root, int x){
    if(root == NULL){
        return root;
    }
    if(x < root->data){
        root->left = delete(root->left, x);
    }
    else if(x > root->data){
        root->right = delete(root->right, x);
    }
    else{ //silinecek dugum bulunmus ise
        if(root->left == NULL || root->right == NULL){ //eger cocuk yoksa temp NULL degerini aliyor fakat bi cocuk varsa cocuk temp e ataniyor 
            AVLTREE *temp = root->left ? root->left : root->right;
            if(temp == NULL){
                temp = NULL;
                root = NULL;
            }
            else{
                *root = *temp;
            }
            free(temp);
        }
        else{ //silinecek dugumun iki cocugu varsa
            AVLTREE *temp = minValue(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }

    if(root == NULL){
        return root;
    }

    root->height = maxValue(height(root->left), height(root->right)) + 1;

    if(getBalance(root) > 1 && getBalance(root->left) >= 0){
        return rightRotate(root);
    }

    if(getBalance(root) > 1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(getBalance(root) < -1 && getBalance(root->right) <= 0){
        return leftRotate(root);
    }

    if(getBalance(root) < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}*/

int main(){
    AVLTREE *myroot = NULL;
    int key, select;
    printf("Enter the value: Type -1 to exit: ");
    scanf("%d", &key);
    while(key != 1){
        myroot = insertToAVL(key,myroot);
        scanf("%d", &key);
    }
    do{
        printf("\n1.Insert\n2.Height\n3.Inorder\n4.Exit\nChoose >");
        scanf("%d", &select);
        switch(select){
            case 1:
                printf("Enter a value... ");
                scanf("%d", &key);
                myroot = insertToAVL(key,myroot);
                break;
            case 2: 
                printf("Height = %d", myroot->height);
                break;
            case 3:
                inorder(myroot);
                break;
            case 4:
                return 0;
                break;
            default:
                printf("Invalid choice");
                break;
        }
    }while(1);

    return 0;
}