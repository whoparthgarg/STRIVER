//time: O(n)
//space: O(1)
vector<int> Solution::repeatedNumber(const vector<int> &nums) 
{
    int n=nums.size();
    
    // take xor of all elements
    int x=0;
    for(auto e:nums)
    {
        x^=e;
    }
    
    // take xor from 1 to n
    for(int i=1;i<=n;i++)
    {
        x^=i;
    }
    
    // get rightmost setbit of x
    int set_bit=x&~(x-1);
    
    // now there are two types of elements:
    // 1.elements with same bit as in set_bit
    // 2.elements with not having same bit set in set_bit
    int res1=0;
    int res2=0;
    
    for(auto e:nums)
    {
        if(set_bit&e)
        {
            res1^=e;
        }
        else
        {
            res2^=e;
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        if(set_bit&i)
        {
            res1^=i;
        }
        else
        {
            res2^=i;
        }
    }
    
    // find which is missing and repeating
    bool flag=false;
    for(auto x:nums)
    {
        if(x==res1)
        {
            return {res1,res2};
        }
    }
    
    return {res2,res1};
}
