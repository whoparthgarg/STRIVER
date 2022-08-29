//time: O(n*n)
//space: O(m*3) m:number of triplets
vector<vector<int>> threeSum(vector<int>& nums) 
{
    int n=nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    
    for(int i=0;i<n;i++)
    {
        int low=i+1;
        int high=n-1;
        
        int new_target=0-nums[i];
        
        while(low<high)
        {
            int curr_sum=nums[low]+nums[high];
            
            if(curr_sum==new_target)
            {
                res.push_back({nums[i],nums[low],nums[high]});
                
                while(low<high and nums[low]==nums[low+1])
                {
                    low++;
                }
                
                while(low<high and nums[high]==nums[high-1])
                {
                    high--;
                }
                
                low++;
                high--;
            }
            else if(curr_sum>new_target)
            {
                high--;
            }
            else
            {
                low++;
            }
        }
        
        while(i+1<n and nums[i]==nums[i+1])
        {
            i++;
        }
    }
    
    return res;
}