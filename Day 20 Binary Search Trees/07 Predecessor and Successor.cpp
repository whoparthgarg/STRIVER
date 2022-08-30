//time: O(h)
//space: O(1)
void findPreSuc(Node* root, Node*& pre, Node*& suc, int target)
{
    while(root)
    {
        if(root->key==target)
        {
            if(root->left)
            {
                pre=root->left;
            }
            if(root->right)
            {
                suc=root->right;
            }
            root=root->left;
        }
        else
        {
            if(root->key<target)
            {
                pre=root;
                root=root->right;
            }
            else
            {
                suc=root;
                root=root->left;
            }
        }
    }
}