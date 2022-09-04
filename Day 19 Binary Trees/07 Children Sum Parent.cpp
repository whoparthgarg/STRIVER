//time: O(n)
//space: O(n)
//this code is to check children sum property
int isSumProperty(Node *root)
{
    if(root==NULL)
    {
        return true;
    }
    
    if(root->left==NULL and root->right==NULL)
    {
        return true;
    }
    
    int sum=0;
    
    if(root->left)
    {
        sum+=root->left->data;
    }
    
    if(root->right)
    {
        sum+=root->right->data;
    }
    
    return (sum==root->data and isSumProperty(root->left) and isSumProperty(root->right));
}

//real code
void changeTree(BinaryTreeNode<int>* root) 
{
    if(root==NULL)
    {
        return ;
    }
    
    int sum=0;
    if(root->left)
    {
        sum+=root->left->data;
    }
    if(root->right)
    {
        sum+=root->right->data;
    }
    
    if(sum<root->data)
    {
        if(root->left)
        {
            root->left->data=root->data;
        }
        else if(root->right)
        {
            root->right->data=root->data;
        } 
    }
    
    changeTree(root->left);
    changeTree(root->right);
    
    int total=0;
    if(root->left)
    {
        total+=root->left->data;
    }
    if(root->right)
    {
        total+=root->right->data;
    }
    if(root->left or root->right)
    {
        root->data=total;
    }
}  