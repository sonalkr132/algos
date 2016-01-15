#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

int m = 0;

struct node
{
    int key, freq;
    struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->freq = 1;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        if(root->freq > 1) printf("%d\n", root->key);
        inorder(root->right);
    }
}
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else if(key == node->key){
      node->freq++;
      if(node->freq == 2) m++;
    }

    /* return the (unchanged) node pointer */
    return node;
}

int main(){
  int n1, n2, n3;
  //cin >> n1 >> n2 >> n3;

  int total = 1000000, input;

  //cin >> input;
  struct node *root = NULL;
  root = insert(root, 10);

  while(total--){
    //cin >> input;
    input = rand()%100000;
    insert(root, input);
  }
  cout << m <<endl;
  //inorder(root);

  return 0;
}
