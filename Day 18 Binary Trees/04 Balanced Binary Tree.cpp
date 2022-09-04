//time: O(n*n)
//space: O(n)
int height(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    
    int lh=height(root->left);
    int rh=height(root->right);
    
    return 1+max(lh,rh);
}
bool isBalanced(TreeNode* root) {
    if(root==NULL)
    {
        return true;
    }
    
    int lh=height(root->left);
    int rh=height(root->right);
    
    return (abs(lh-rh)<=1 and isBalanced(root->left) and isBalanced(root->right));
}

//time: O(n)
//space: O(h)
int height(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    
    int lh=height(root->left);
    if(lh==-1)
    {
        return -1;
    }
    
    int rh=height(root->right);
    if(rh==-1)
    {
        return -1;
    }
    
    if(abs(lh-rh)>1)
    {
        return -1;
    }
    
    return 1+max(lh,rh);
}
bool isBalanced(TreeNode* root) {
    return height(root)!=-1;
}