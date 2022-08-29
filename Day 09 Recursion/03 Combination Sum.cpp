//time: O()
//space: O()
void solve(vector<int> &nums,int i,vector<int> &temp,vector<vector<int>> &res,int cs,int ts)
{
    if(cs>ts)
    {
        return ;
    }
    
    if(cs==ts)
    {
        res.push_back(temp);
        return ;
    }
    
    for(int j=i;j<nums.size();j++)
    {
        temp.push_back(nums[j]);
        cs+=nums[j];
        solve(nums,j,temp,res,cs,ts);
        temp.pop_back();
        cs-=nums[j];
    }
}
vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    vector<int> temp;
    solve(nums,0,temp,res,0,target);
    return res;
}