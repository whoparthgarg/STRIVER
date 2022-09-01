//time: O(n)
//space: O(n)
//this code is to check children sum property
int isSumProperty(Node *root)
{
    if(root==NULL)
    {
        return true;
    }
    
    if(root->left==NULL and root->right==NULL)
    {
        return true;
    }
    
    int sum=0;
    
    if(root->left)
    {
        sum+=root->left->data;
    }
    
    if(root->right)
    {
        sum+=root->right->data;
    }
    
    return (sum==root->data and isSumProperty(root->left) and isSumProperty(root->right));
}

//real code
void reorder(BinaryTreeNode<int> * root) {
  if (root == NULL) return;
  int child = 0;
  if (root -> left) {
    child += root -> left -> data;
  }
  if (root -> right) {
    child += root -> right -> data;
  }

  if (child < root -> data) {
    if (root -> left) root -> left -> data = root -> data;
    else if (root -> right) root -> right -> data = root -> data;
  }

  reorder(root -> left);
  reorder(root -> right);

  int tot = 0;
  if (root -> left) tot += root -> left -> data;
  if (root -> right) tot += root -> right -> data;
  if (root -> left || root -> right) root -> data = tot;
}
void changeTree(BinaryTreeNode < int > * root) {
    reorder(root);
}  