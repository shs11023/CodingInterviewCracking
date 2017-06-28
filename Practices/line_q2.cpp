/*
Please implement a program that
lists the nodes of a random binary tree by nodes at the same depth.
*/
#include <queue>

typedef struct _node {
  int value;
  struct _node * left;
  struct _node * right;
}node;


node* makeRandomTree (int arr[], int len) {
  std::queue<node*> makeq;
  int idx = 0;

  node* root = new node;
  root->value = arr[idx];
  makeq.push(root);

  while(!makeq.empty()) {
    node* child = makeq.front();
    makeq.pop();

    child->left = child->right =  NULL;
printf("idx(%d) %d\n", idx, child->value);
    if(++idx<len) {
      node* leftchild = new node;
      leftchild->value = arr[idx];
      child->left = leftchild;
      makeq.push(leftchild);
    }
    if(++idx<len) {
      node* rightchild = new node;
      rightchild->value = arr[idx];
      child->right = rightchild;
      makeq.push(rightchild);
    }
  }
  return root;
}

void printListFromRandomTree (node*root) {
  std::queue<node*> travelq;
  travelq.push(root);
  while(!travelq.empty()) {
    node* child = travelq.front();
    travelq.pop();

    printf("%d ", child->value);

    if(child->left) travelq.push(child->left);
    if(child->right) travelq.push(child->right);
  }
  printf("\n");
}

int main(void)
{
  int len = 15;
  int arr[] = {7, 3, 11, 1, 5, 9, 13, 0, 2, 4, 6, 8, 10, 12, 14};

  node* root = makeRandomTree (arr, len);
  printListFromRandomTree (root);
  return 0;
}
