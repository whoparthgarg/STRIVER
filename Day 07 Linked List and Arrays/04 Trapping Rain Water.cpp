//brute force
//time: O(n)
//space: O(n)
int trap(vector<int>& height) 
{
    int n=height.size();
    
    vector<int> left(n,0);
    vector<int> right(n,0);
    
    for(int i=1;i<n;i++)
    {
        left[i]=max(left[i-1],height[i-1]);
    }
    
    for(int i=n-2;i>=0;i--)
    {
        right[i]=max(right[i+1],height[i+1]);
    }
    
    int res=0;
    for(int i=0;i<n;i++)
    {
        int h=min(left[i],right[i]);
        if(h>height[i])
        {
            res+=h-height[i];
        }
    }
    
    return res;
}

//optimised
//time: O(n)
//space: O(1)
int trap(vector<int>& height) 
{
    int n=height.size();
    
    int left_max=0;
    int right_max=0;
    
    int left=0;
    int right=n-1;
    
    int res=0;
    
    while(left<right)
    {
        if(height[left]<height[right])
        {
            left_max=max(left_max,height[left]);
            res+=left_max-height[left++];
        }
        else
        {
            right_max=max(right_max,height[right]);
            res+=right_max-height[right--];
        }
    }
    
    return res;
}