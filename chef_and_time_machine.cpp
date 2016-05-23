#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


struct node
{
    int key;
    int count;
    struct node *left, *right;
};
// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    temp->count = 1;
    return temp;
}
// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d(%d) ", root->key, root->count);
        inorder(root->right);
    }
}

/* Given a non-empty binary search tree, return the node with
   minimum key value found in that tree. Note that the entire
   tree does not need to be searched. */
struct node * minValueNode(struct node* node)
{
    struct node* current = node;
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
    return current;
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
    // If key already exists in BST, icnrement count and return
    if (key == node->key)
    {
       (node->count)++;
        return node;
    }
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    /* return the (unchanged) node pointer */
    return node;
}

int ans=0;

/* Given a binary search tree and a key, this function
   deletes a given key and returns root of modified tree */
struct node* deleteNode(struct node* root, int key)
{
    // If the key to be deleted is smaller than the
    // root's key, then it lies in left subtree
    if (key < root->key && root->left != NULL)
        root->left = deleteNode(root->left, key);
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key && root->right != NULL)
        root->right = deleteNode(root->right, key);
    // if key is same as root's key
    else
    {
        ans+=(key-root->key);
        // If key is present more than once, simply decrement
        // count and return
        if (root->count > 1)
        {
           (root->count)--;
           return root;
        }
        // ElSE, delete the node
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(root->right);
        // Copy the inorder successor's content to this node
        root->key = temp->key;
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main(){
  int cases;

  cin >> cases;
  while(cases--){
    int N, K, M;
    cin >> N >> K >> M;
    int planned[N], completed[N];
    for(int i=0; i<N; i++) cin >> planned[i];
    for(int i=0; i<N; i++) cin >> completed[i];

    int total = K+M;
    struct node *root = NULL;

    while(total--){
      int input;
      cin >> input;
      root = insert(root, input);
    }

    for(int i=0; i<N; i++){
      int diff = planned[i] - completed[i];
      if(diff == 0) continue;
      deleteNode(root, diff);
    }
    cout << ans<<endl;
    ans = 0;
  }

  return 0;
}
