//time: O(2^n*k) k:average length of subset
//space: O(2^n*k)
//subset 1
void solve(vector<int> &nums,int i,vector<int> &temp,vector<vector<int>> &res)
{
    res.push_back(temp);
    for(int j=i;j<nums.size();j++)
    {
        temp.push_back(nums[j]);
        solve(nums,j+1,temp,res);
        temp.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums) 
{
    vector<vector<int>> res;
    vector<int> temp;
    solve(nums,0,temp,res);
    return res;
}

//time: O(2^n*k)
//space: O(2^n*k)
//subset 2
void solve(vector<int> &nums,int i,vector<int> &temp,vector<vector<int>> &res)
{
    res.push_back(temp);
    for(int j=i;j<nums.size();j++)
    {
        if(j==i or nums[j-1]!=nums[j])
        {
            temp.push_back(nums[j]);
            solve(nums,j+1,temp,res);
            temp.pop_back();
        }
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) 
{
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    vector<int> temp;
    solve(nums,0,temp,res);
    return res;
}
