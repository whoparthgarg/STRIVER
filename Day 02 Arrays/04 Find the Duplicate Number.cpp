//modifying array
//time: O(n)
//space: O(1)
int findDuplicate(vector<int>& nums) 
{
    int n=nums.size();
    
    for(int i=0;i<n;i++)
    {
        int idx=abs(nums[i])-1;
        if(nums[idx]<0)
        {
            return (idx+1);
        }
        else
        {
            nums[idx]=-nums[idx];
        }
    }
    
    return -1;
}

//without modifying array
//time: O(n)
//space: O(1)
int findDuplicate(vector<int>& nums) 
{
    int slow=nums[0];
    int fast=nums[nums[0]];
    
    while(slow!=fast)
    {
        slow=nums[slow];
        fast=nums[nums[fast]];
        
        if(slow==fast)
        {
            slow=0;
            while(slow!=fast)
            {
                slow=nums[slow];
                fast=nums[fast];
            }
            
            return slow;
        }
    }
    
    return nums[0];
}