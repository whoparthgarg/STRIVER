//time: O(h)
//space: O(1)
TreeNode* searchBST(TreeNode* root, int target) 
{
    if(root==NULL)
    {
        return root;
    }
    
    while(root)
    {
        if(root->val==target)
        {
            return root;
        }
        else if(root->val>target)
        {
            root=root->left;
        }
        else
        {
            root=root->right;
        }
    }
    
    return NULL;
}