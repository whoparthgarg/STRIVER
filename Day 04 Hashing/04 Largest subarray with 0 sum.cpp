//time: O(n)
//space: O(n)
int maxLen(vector<int>& nums, int n)
{   
    unordered_map<int,int> m;
    int presum=0;
    int max_len=0;
    
    for(int i=0;i<n;i++)
    {
        presum+=nums[i];
        
        if(presum==0)
        {
            max_len=max(max_len,i+1);
        }
        
        if(m.find(presum)!=m.end())
        {
            max_len=max(max_len,i-m[presum]);
        }
        else
        {
            m[presum]=i;
        }
    }
    
    return max_len;
}