//time: O(n)
//space: O(n)
vector<int> v;
vector<int> inorder(TreeNode* root)
{
    if(root==NULL)
    {
        return {};
    }
    
    //inorder is left root right
    inorder(root->left);
    v.push_back(root->val);
    inorder(root->right);
    
    return v;
}

bool isSorted(vector<int> nums)
{
    int n=nums.size();
    for(int i=1;i<n;i++)
    {
        if(nums[i-1]>=nums[i])
        {
            return false;
        }
    }
    
    return true;
}
bool isValidBST(TreeNode* root) {
    if(root==NULL)
    {
        return true;
    }
    
    vector<int> inorderVector=inorder(root);
    
    if(isSorted(inorderVector))
    {
        return true;
    }
    
    return false;
}

//time: O(n)
//space: O(n)
bool inorder(TreeNode* root,TreeNode* &prev)
{
    if(root==NULL)
    {
        return true;
    }
    
    //left 
    if(inorder(root->left,prev)==false)
    {
        return false;
    }
    
    //root
    if(prev!=NULL and prev->val>=root->val)
    {
        return false;
    }
    prev=root;
    
    //right
    if(inorder(root->right,prev)==false)
    {
        return false;
    }
    
    return true;
}

bool isValidBST(TreeNode* root) {
    TreeNode* prev=NULL;
    return inorder(root,prev);
}
