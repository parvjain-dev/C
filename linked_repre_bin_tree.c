#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int val)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preorder_traverse(struct node *root)
{

    if (root != NULL)
    {
        printf("%d  ", root->data);
        preorder_traverse(root->left);
        preorder_traverse(root->right);
    }
 }
 void postorder_traversal(struct node * root){
     
       if (root!=NULL)
       {
              postorder_traversal(root->left);
              postorder_traversal(root->right);
              printf("%d   ",root->data);
       }
       
 }
 void Inorder_traversal(struct node * root){
     
       if (root!=NULL)
       {
              Inorder_traversal(root->left);
              printf("%d   ",root->data);
              Inorder_traversal(root->right);
       }
       
 }
int main()
{
    //  //            4
    //              /   \
    //             1      4
    //            / \     / \
    //           11  12   N  3
    struct node *root = createnode(2);
    struct node *child1 = createnode(1);
    struct node *child2 = createnode(4);
    struct node *cchild1 = createnode(11);
    struct node *cchild2 = createnode(12);
    struct node *cchild3 = createnode(3);
    root->left = child1;
    root->right = child2;
    child1->left = cchild1;
    child1->right = cchild2;
    child2->right = cchild3;


    
     printf("Preorder for given tree is\n");
    preorder_traverse(root);
    printf("\n");
     printf("Postorder for given tree is\n");
    postorder_traversal(root);
    printf("\n");
     printf("Inorder for given tree is\n");
    Inorder_traversal(root);
    return 0;
}












/*
REPETATIONS ARE THERE TO GET RID FROM REPETATION WE USE FUNCTION CREATE NODE

    struct node *root;
    root = (struct node *)malloc(sizeof(struct node));
    root->data = 12;
    //This is empty root node means no children
    root->left = NULL;
    root->right = NULL;

    struct node *child1;
    child1 = (struct node *)malloc(sizeof(struct node));
    child1->data = 32;
    //This is childern 1 or (left) of root
    child1->left = NULL;
    child1->right = NULL;

    struct node *child2;
    child2 = (struct node *)malloc(sizeof(struct node));
    child2->data = 5;
    //This is chuldern2 or (right) of root
    child2->left = NULL;
    child2->right = NULL;

//Linking the root node with left and right
    root->left = child1;
    root->right = child2;
*/
