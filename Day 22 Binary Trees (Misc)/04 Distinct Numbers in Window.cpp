//time: O(n)
//space: O(n)
vector<int> Solution::dNums(vector<int> &nums, int k) {
    int n=nums.size();
    vector<int> res;
    unordered_map<int,int> m;
    int cnt=0;
    for(int i=0;i<k;i++)
    {
        if(m[nums[i]]==0)
        {
            cnt++;
        }
        m[nums[i]]++;
    }
    
    res.push_back(cnt);
    
    for(int i=k;i<n;i++)
    {
        if(m[nums[i-k]]==1)
        {
            cnt--;
        }
        m[nums[i-k]]--;
        
        if(m[nums[i]]==0)
        {
            cnt++;
        }
        m[nums[i]]++;
        res.push_back(cnt);
    }
    
    return res;
}
