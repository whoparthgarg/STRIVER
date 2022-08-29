//time: O(n)
//space: O(n)
int longestConsecutive(vector<int>& nums) 
{
    int n=nums.size();
    unordered_set<int> s(nums.begin(),nums.end());
    int max_cnt=0;
    
    for(auto x:nums)
    {
        int cnt=1;
        if(s.find(x-1)==s.end())
        {
            while(s.find(x+1)!=s.end())
            {
                cnt++;
                x++;
            }
        }
        max_cnt=max(max_cnt,cnt);
    }
    
    return max_cnt;
}