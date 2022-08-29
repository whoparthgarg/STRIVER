//time: O(n)
//space: O(1)
vector<int> majorityElement(vector<int>& nums) 
{
    int n=nums.size();
    
    int res1=INT_MAX;
    int res2=INT_MAX;
    
    int cnt1=0;
    int cnt2=0;
    
    for(auto x:nums)
    {
        if(x==res1)
        {
            cnt1++;
        }
        else if(x==res2)
        {
            cnt2++;
        }
        else if(cnt1==0)
        {
            res1=x;
            cnt1=1
        }
        else if(cnt2==0)
        {
            res2=x;
            cnt2=1
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    
    cnt1=cnt2=0;
    
    vector<int> res;
    
    for(auto x:nums)
    {
        if(x==res1)
        {
            cnt1++;
        }
        else if(x==res2)
        {
            cnt2++;
        }
    }
    
    if(cnt1>(n/3))
    {
        res.push_back(res1);
    }
    
    if(cnt2>(n/3))
    {
        res.push_back(res2);
    }
    
    return res;
}