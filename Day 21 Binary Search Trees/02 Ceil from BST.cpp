//time: O(h)
//space: O(1)
int findCeil(BinaryTreeNode<int> *root, int x)
{
    int res=-1;
    
    while(root)
    {
        if(root->data==x)
        {
            return x;
        }
        else if(root->data<x)
        {
            root=root->right;
        }
        else
        {
            res=root->data;
            root=root->left;
        }
    }
    
    return res;
}