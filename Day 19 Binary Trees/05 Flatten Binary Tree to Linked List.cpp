//time: O(n)
//space: O(1)
void flatten(TreeNode* root) 
{
    while(root)
    {
        if(root->left)
        {
            TreeNode* temp=root->left;
            while(temp->right)
            {
                temp=temp->right;
            }
            temp->right=root->right;
            root->right=root->left;
            root->left=NULL;
        }
        root=root->right;
    }
}