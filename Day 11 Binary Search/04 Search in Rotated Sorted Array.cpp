//time: O(logN)
//space: O(1)
int search(vector<int>& nums, int target) 
{
    int n=nums.size();
    int low=0;
    int high=n-1;
    
    while(low<=high)
    {
        int mid=(low+high)>>1;
        
        if(nums[mid]==target)
        {
            return mid;
        }
        else if(nums[low]<nums[mid])
        {
            //left part is sorted
            if(nums[low]==target)
            {
                return low;
            }
            else if(nums[low]<target and target<nums[mid])
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        else
        {
            //right part is sorted
            if(nums[high]==target)
            {
                return high;
            }
            else if(nums[mid]<target and target<nums[high])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
    }
    
    return -1;
}