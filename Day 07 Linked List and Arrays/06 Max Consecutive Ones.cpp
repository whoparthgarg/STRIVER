//time: O(n)
//space: O(1)
int findMaxConsecutiveOnes(vector<int>& nums) 
{
    int n=nums.size();
    int max_cnt=0;
    int cnt=0;
    
    for(auto x:nums)
    {
        if(x==1)
        {
            cnt++;
            max_cnt=max(max_cnt,cnt);
        }
        else
        {
            cnt=0;
        }
    }
    
    return max_cnt;
}