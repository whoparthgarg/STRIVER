//time: O(h)
//space: O(1)
int floorInBST(TreeNode<int> * root, int x)
{
    int res=INT_MAX;
    
    while(root)
    {
        if(root->val==x)
        {
            return x;
        }
        else if(root->val>x)
        {
            root=root->left;
        }
        else
        {
            res=root->val;
            root=root->right;
        }
    }
    
    return res;
}