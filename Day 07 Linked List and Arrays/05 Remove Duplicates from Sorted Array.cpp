//time: O(n)
//space: O(1)
int removeDuplicates(vector<int>& nums) 
{
    int n=nums.size();
    int res=1;
    
    for(int i=1;i<n;i++)
    {
        if(nums[i]!=nums[res-1])
        {
            nums[res]=nums[i];
            res++;
        }
    }
    
    return res;
}
    
