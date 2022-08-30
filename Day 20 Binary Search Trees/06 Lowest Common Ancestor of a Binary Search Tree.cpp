//time: O(h)
//space: O(1)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    while(root)
    {
        if(root->val>p->val and root->val>q->val)
        {
            root=root->left;
        }
        else if(root->val<p->val and root->val<q->val)
        {
            root=root->right;
        }
        else
        {
            break;
        }
    }
    
    return root;
}