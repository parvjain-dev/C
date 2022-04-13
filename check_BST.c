#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * right;
    struct node * left;
};

struct node * createnode(int data){
    struct node * n = (struct node *)malloc(sizeof(struct node));
    n->left=NULL;
    n->right=NULL;
    n->data = data;
    return n;
}
void in_order(struct node * r){
    if (r!=NULL)
    {
        in_order(r->left);
        printf("%d  ",r->data);
        in_order(r->right);
    }
    
}
int BST(struct node * r){
    //Prev ->voh node jiske childern ko haaam check kar rhe hai
  static struct node * prev =NULL; //Here we not checking any children we are checkng root only

    if (r!=NULL)
    {
       if (!BST(r->left))   //it means we are checking left subtree if left subtree is not BST then return 0
       {
           return 0;
       }
       if (prev!=NULL && r->data<=prev->data)   //prev Null means we are cheking root
       {
           return 0;
       }
       prev=r;
       return BST(r->right);
       
    }
    else{
        //we consider a empty tree as BST
        return 1;
    }
}
int main(int argc, char const *argv[])
{
    struct node * root = createnode(9);
    struct node *child1 = createnode(4);
    struct node * cchild1 = createnode(2);
    struct node * cchild2 = createnode(7);
    struct node * ccchild1 = createnode(5);
    struct node * ccchild2 = createnode(8);
    struct node * child2 = createnode(11);
    struct node * cchild21 = createnode(15);
    struct node *  ccchild31= createnode(14);
     root->left=child1;
     root->right=child2;
     child1->left=cchild1;
     child1->right=cchild2;
     cchild2->left=ccchild1;
     cchild2->right=ccchild2;
     child2->right=cchild21;
     cchild21->left=ccchild31;
       
      if (BST(root))
      {
          in_order(root);
          printf("\n");
          printf("Yes it is BST\n");
      }
      else{
              in_order(root);
          printf("\n");
          printf("Not a BST\n");
      }
      
    return 0;
}
