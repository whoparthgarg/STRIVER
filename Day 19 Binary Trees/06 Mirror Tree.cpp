//time: O(n)
//space: O(n)
void mirror(Node* root) 
{
    if(root==NULL)
    {
        return ;
    }

    if(root->left and root->right)
    {
        auto temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
    else if(root->left==NULL and root->right)
    {
        root->left=root->right;
        root->right=NULL;
    }
    else if(root->left and root->right==NULL)
    {
        root->right=root->left;
        root->left=NULL;
    }
    
    mirror(root->left);
    mirror(root->right);
}