#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node* left;
struct node* right;
};
typedef struct node* NODE;
NODE createNode(int value) {
NODE newNode = (NODE)malloc(sizeof(struct node));
newNode->data = value;
newNode->left = newNode->right = NULL;
return newNode;
}
NODE insert(NODE root, int value) {
if (root == NULL) return createNode(value);
if (value < root->data)
root->left = insert(root->left, value);
else if (value > root->data)
root->right = insert(root->right, value);
return root;
}

NODE findMin(NODE root) {
while (root->left != NULL)
root = root->left;
return root;
}

NODE deleteNode(NODE root, int value) {
if (root == NULL) return root;
if (value < root->data)
root->left = deleteNode(root->left, value);
else if (value > root->data)
root->right = deleteNode(root->right, value);
else {
if (root->left == NULL) {
NODE temp = root->right;
free(root);
return temp;
} else if (root->right == NULL) {
NODE temp = root->left;
free(root);
return temp;
}
NODE temp = findMin(root->right);
root->data = temp->data;
root->right = deleteNode(root->right, temp->data);
}
return root;
}
void inorder(NODE root) {
if (root != NULL) {
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
}
void preorder(NODE root) {
if (root != NULL) {
printf("%d ", root->data);
preorder(root->left);
preorder(root->right);
}
}
void postorder(NODE root) {
if (root != NULL) {
postorder(root->left);
postorder(root->right);
printf("%d ", root->data);
}
}
int main() {
NODE root = NULL;
root = insert(root, 50);
root = insert(root, 30);
root = insert(root, 70);
root = insert(root, 20);
root = insert(root, 40);
root = insert(root, 60);
root = insert(root, 80);
printf("Inorder traversal: ");
inorder(root);
printf("\n");
printf("Preorder traversal: ");
preorder(root);
printf("\n");
printf("Postorder traversal: ");
postorder(root);
printf("\n");
root = deleteNode(root, 50);
printf("Inorder after deleting 50: ");
inorder(root);
printf("\n");
return 0;
}

o/p

  Inorder traversal: 20 30 40 50 60 70 80
Preorder traversal: 50 30 20 40 70 60 80
Postorder traversal: 20 40 30 60 80 70 50
Inorder after deleting 50: 20 30 40 60 70 80
