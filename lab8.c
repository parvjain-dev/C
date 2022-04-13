#include <stdio.h>
#include <stdlib.h>
struct node
{
int key;
struct node *left, *right;
};
struct node *newNode(int item)
{
struct node *temp = (struct node*)malloc(sizeof(struct node));
temp->key = item;
temp->left = temp->right = NULL;
return temp;
}
void inorder(struct node *root)
{
if(root != NULL)
{
inorder(root->left);
printf("%d ", root->key);
inorder(root->right);
}
}
struct node* insert(struct node* node, int key)
{
if(node == NULL) return newNode(key);
if(key < node->key) node->left = insert(node->left, key);
else if(key > node->key) node->right = insert(node->right, key);
return node;
}
struct node * minValueNode(struct node* node)
{
struct node* current = node;
while(current && current->left != NULL) current = current->left;
return current;
}
struct node* deleteNode(struct node* root, int key)
{
if(root == NULL) return root;
if(key < root->key) root->left = deleteNode(root->left, key);
else if(key > root->key) root->right = deleteNode(root->right,
key);
else
{
if(root->left == NULL)
{
struct node *temp = root->right;
free(root);
return temp;
}
else if(root->right == NULL)
{
struct node *temp = root->left;
free(root);
return temp;
}
struct node* temp = minValueNode(root->right);
root->key = temp->key;
root->right = deleteNode(root->right, temp->key);
}
return root;
}
int main()
{
printf("Parv Jain, 200905316\n");
struct node *root = NULL;
printf("Enter the root element : ");
int key = 0;
scanf("%d", &key);
root = insert(root,key);
printf("MENU\nEnter 1 to Enter an element\nEnter 2 to Delete an element\nEnter 3 to Display BST\nEnter 4 to Exit\n");
int choice = 0;
while(choice < 5)
{
printf("Enter choice : ");
scanf("%d", &choice);
if(choice == 1)
{
printf("Enter element to be inserted : ");
scanf("%d", &key);
insert(root, key);
}
if(choice == 2)
{
printf("Enter element to be deleted : ");
scanf("%d", &key);
root = deleteNode(root, key);
}
if(choice == 3)
{
printf("BST : ");
inorder(root);
printf("\n");
}
if(choice == 4)
{
printf("Exiting...");
exit(0);
}
}
return 0;
}