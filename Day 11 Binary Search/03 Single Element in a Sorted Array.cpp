//time: O(logN)
//space: O(1)
int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        
        if(n==1)
        {
            return nums[0];
        }
        
        int low=0;
        int high=n-1;
        
        while(low<=high)
        {
            int mid=(low+high)>>1;
            
            //check single element at low or high side
            if((mid%2==0 and nums[mid]==nums[mid+1]) or (mid%2==1 and nums[mid]==nums[mid-1]))
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        
        return nums[low];
    }