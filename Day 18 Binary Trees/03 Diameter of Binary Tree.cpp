//time: O(n)
//space: O(logn)
int height(TreeNode* root,int &d)
{
    if(root==NULL)
    {
        return 0;
    }
    
    int lh=height(root->left,d);
    int rh=height(root->right,d);
    d=max(d,lh+rh);
    
    return 1+max(lh,rh);
}
int diameterOfBinaryTree(TreeNode* root) 
{
    int d=0;
    height(root,d);
    return d;
}