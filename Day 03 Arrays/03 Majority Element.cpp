//time: O(n)
//space: O(1)
int majorityElement(vector<int>& nums) 
{
    int n=nums.size();
    int res=0;
    int cnt=1;
    
    for(int i=0;i<n;i++)
    {
        if(nums[i]==nums[res])
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
        
        if(cnt==0)
        {
            cnt=1;
            res=i;
        }
    }
    
    return nums[res];
}