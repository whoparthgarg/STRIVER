//time: O(n)
//space: O(logn)
int d=0;
int height(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    
    return (1+max(height(root->left),height(root->right)));
}
int diameterOfBinaryTree(TreeNode* root) {
    if(root==NULL)
    {
        return 0;
    }
    
    int d1=height(root->left);
    int d2=height(root->right);
    d=max(d,d1+d2);
    
    return d;
}