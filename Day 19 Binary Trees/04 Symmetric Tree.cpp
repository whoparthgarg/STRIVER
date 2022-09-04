//time: O(n)
//space: O(n)
bool check(TreeNode* p,TreeNode* q)
{
    if(p==NULL and q==NULL)
    {
        return true;
    }
    
    if(p==NULL or q==NULL)
    {
        return false;
    }
    
    if(p->val!=q->val)
    {
        return false;
    }
    
    return check(p->left,q->right) and check(p->right,q->left);
}
bool isSymmetric(TreeNode* root) {
    if(root==NULL)
    {
        return true;
    }
    
    return check(root->left,root->right);
}