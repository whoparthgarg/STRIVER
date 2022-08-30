//time: O(n)
//space: O(n)
TreeNode* solve(vector<int> &nums,int &i,int bound)
{
    if(i==nums.size() or nums[i]>bound)
    {
        return NULL;
    }
    
    TreeNode* root=new TreeNode(nums[i++]);
    root->left=solve(nums,i,root->val);
    root->right=solve(nums,i,bound);
    return root;
}
TreeNode* bstFromPreorder(vector<int>& nums) 
{
    int i=0;
    return solve(nums,i,INT_MAX);
}