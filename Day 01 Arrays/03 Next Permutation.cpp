//time: O(n)
//space: O(1)
void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        
        int k;
        for(k=n-2;k>=0;k--)
        {
            if(nums[k]<nums[k+1])
            {
                break;
            }
        }
        
        if(k<0)
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
            int l;
            for(l=n-1;l>k;l--)
            {
                if(nums[l]>nums[k])
                {
                    break;
                }
            }
            swap(nums[l],nums[k]);
            reverse(nums.begin()+k+1,nums.end());
        }
    }