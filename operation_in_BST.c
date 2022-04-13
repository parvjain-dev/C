#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node *createnode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->left = NULL;
    n->right = NULL;
    n->data = data;
    return n;
}
void in_order(struct node *r)
{
    if (r != NULL)
    {
        in_order(r->left);
        printf("%d  ", r->data);
        in_order(r->right);
    }
}
struct node *search_key(struct node *root, int key)
{
    if (root == NULL)

    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search_key(root->left, key);
    }
    else
    {
        return search_key(root->right, key);
    }
}

struct node *searchiter(struct node *root, int key)
{
    while (root != NULL)
    {

        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left; //here we are changing root element
        }
        else
        {
            root = root->right; //we dont need to mention elseif for root->right because if it is not greater not equal then obvios it is less
        }
    }

    //if in starting only our root == NULL
    return NULL;
}
void insertion_in_bst(struct node *root, int key)
{
    struct node *prev = NULL;
    struct node *ptr;
    struct node *newnode = createnode(key);
    while (root != NULL)
    {
        //previous holds the previous value from root always
        prev = root;
        if (key == root->data)
        {
            printf("Duplication occur so, cannot insert");
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    //linkageof new node
    if (key < prev->data)
    {
        prev->left = newnode;
    }
    else
    {
        prev->right = newnode;
    }
}

//inorderpredecessor is like left sub tree -> right most child for understanding write inorder traversal and check who is predecessor for given element
struct node *inOrderPredecessor(struct node* root){
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}


// struct node *deletion(struct node *root, int key)
// {
//      struct node * ipre;
//     if (root == NULL)
//     {
//         return NULL;
//     }

//     //BASE CASE
//     if (root->left == NULL && root->right == NULL) //HERE WE ARE IN LEAF NODE YOU CAN TAKE DOUBLY LINKEDLIST FOR UNDERSTANDING
//     {
//         free(root);
//        return NULL;
//     }
//     //search for element to be deleted
//     if ( key< root->data)
//     {
//         root->left=deletion(root->left, key);
//     }
//     else if (key>root->data)
//     {
//       root->right=  deletion(root->right, key);
//     }
//     //Deletion strategy when the node is found
//     else
//     {
//         //find inorder predecessor
//         ipre = inorderpredecessor(root);                   //here root = key value
//         root->data = ipre->data ;                             //replacing deletion value or key with predecessor
//        root->left =deletion(root->left, ipre->data); //HERE thing are like (apn yeh chezz karte jaynege jab tak voh leaf node pe nhi aa jata )
//     }
//     return root;
// }

struct node *deleteNode(struct node *root, int value){

    struct node* iPre;
    if (root == NULL){
        return NULL;
    }
    if (root->left==NULL&&root->right==NULL){
        free(root);
        return NULL;
    }


    //searching for the node to be deleted
    if (value < root->data){
        root-> left = deleteNode(root->left,value);
    }
    else if (value > root->data){
        root-> right = deleteNode(root->right,value);
    }
    //deletion strategy when the node is found
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}
int main(int argc, char const *argv[])
{
    struct node *root = createnode(9);
    struct node *child1 = createnode(4);
    struct node *cchild1 = createnode(2);
    struct node *cchild2 = createnode(7);
    struct node *ccchild1 = createnode(5);
    struct node *ccchild2 = createnode(8);
    struct node *child2 = createnode(11);
    struct node *cchild21 = createnode(15);
    struct node *ccchild31 = createnode(14);
    root->left = child1;
    root->right = child2;
    child1->left = cchild1;
    child1->right = cchild2;
    cchild2->left = ccchild1;
    cchild2->right = ccchild2;
    child2->right = cchild21;
    cchild21->left = ccchild31;

    // struct node *n = search_key(root, 9);
    // if (n != NULL)
    // {
    //     printf("Found: %d", n->data);
    // }
    // else
    // {
    //     printf("Element not found");
    // }

    // struct node *n = searchiter(root, 78);
    // if (n != NULL)
    // {
    //     printf("Found: %d", n->data);
    // }
    // else
    // {
    //     printf("Element not found");
    // }


    //insertion_in_bst(root, 4);
    //   printf("%d\n",root->right->left->data);



    in_order(root);
   deleteNode(root, 11);
    printf("\n");
    in_order(root);
    return 0;
}
