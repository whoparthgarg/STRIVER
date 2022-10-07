//time: O(n*n)
//space: O(1)
int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxsum=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=nums[j];
                maxsum=max(maxsum,sum);
            }
        }
        
        return maxsum;
    }

//time: O(n)
//space: O(1)
int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int curr_sum=0;
        int max_sum=INT_MIN;
        
        for(auto x:nums)
        {
            curr_sum+=x;
            max_sum=max(max_sum,curr_sum);
            if(curr_sum<0)
            {
                curr_sum=0;
            }
        }
        
        return max_sum;
    }