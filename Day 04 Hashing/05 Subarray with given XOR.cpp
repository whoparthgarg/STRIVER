//time: O(n)
//space: O(n)
int Solution::solve(vector<int> &nums, int k) {
    int n=nums.size();
    int cnt=0;
    int xorr=0;
    unordered_map<int,int> m;
    
    for(auto x:nums)
    {
        xorr^=x;
        
        if(xorr==k)
        {
            cnt++;
        }
        
        if(m.find(xorr^k)!=m.end())
        {
            cnt+=m[xorr^k];
        }
        m[xorr]++;
    }
    
    return cnt;
}
