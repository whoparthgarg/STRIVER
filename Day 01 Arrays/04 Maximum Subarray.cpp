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