//time: O(n*n*n)
//space: O(m*4) m:number of quadraples
vector<vector<int>> fourSum(vector<int>& nums, int target) 
{
    int n=nums.size();
    vector<vector<int>> res;        
    sort(nums.begin(),nums.end());
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            long long new_target=(long long)target-(long long)nums[i]-(long long)nums[j];
            
            int low=j+1;
            int high=n-1;
            
            while(low<high)
            {
                long long sum=(long long)nums[low]+(long long)nums[high];
                
                if(sum==new_target)
                {
                    res.push_back({nums[i],nums[j],nums[low],nums[high]});
                    
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
                else if(sum>new_target)
                {
                    high--;
                }
                else
                {
                    low++;
                }
            }
            
            while(j+1<n and nums[j]==nums[j+1])
            {
                j++;
            }
        }
        
        while(i+1<n and nums[i]==nums[i+1])
        {
            i++;
        }
    }
    
    return res;
}