//time: O(2^n)
//space: O(2^n)
void solve(vector<int> nums,int i,vector<int> &res,int sum)
{
    if(i==nums.size())
    {
        res.push_back(sum);
        return ;
    }
    
    solve(nums,i+1,res,sum+nums[i]);
    solve(nums,i+1,res,sum);
}
vector<int> subsetSums(vector<int> nums, int n)
{
    sort(nums.begin(),nums.end());
    vector<int> res;
    solve(nums,0,res,0);
    return res;
}