//time: O(h)
//space: O(h)
class Solution {
public:
    vector<int> v;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
        {
            return ;
        }
        
        //left root right
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        
        return v[k-1];
    }
};

//time: O(h)
//space: O(k)
int res;
void inorder(TreeNode* root,int &k)
{
    if(root==NULL)
    {
        return ;
    }
    
    //left
    inorder(root->left,k);
    
    //root
    k--;
    if(k==0)
    {
        res=root->val;
        return ;
    }
    
    //right
    inorder(root->right,k);
}
int kthSmallest(TreeNode* root, int k) 
{
    inorder(root,k);
    return res;
}
