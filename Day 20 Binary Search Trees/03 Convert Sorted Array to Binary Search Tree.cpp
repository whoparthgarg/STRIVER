//time: O(n)
//space: O(n)
TreeNode* solve(vector<int> &nums,int low,int high)
{
    if(low>high)
    {
        return NULL;
    }
    
    int mid=(low+high)>>1;
    
    auto temp=new TreeNode(nums[mid]);
    temp->left=solve(nums,low,mid-1);
    temp->right=solve(nums,mid+1,high);
    return temp;
}
TreeNode* sortedArrayToBST(vector<int>& nums) 
{
    return solve(nums,0,nums.size()-1);
}