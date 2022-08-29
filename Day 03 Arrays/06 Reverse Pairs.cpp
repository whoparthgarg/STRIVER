 //time: O(n*logn)
//space: O(n)
int merge(vector<int>& nums,int l,int m,int r)
{
    int n1=m+1-l;
    int n2=r-m;
    
    vector<int> left(n1);
    vector<int> right(n2);
    
    for(int i=0;i<n1;i++)
    {
        left[i]=nums[l+i];
    }
    
    for(int i=0;i<n2;i++)
    {
        right[i]=nums[m+1+i];
    }
    
    int i=0;
    int j=0;
    int k=l;
    int res=0;
    
    while(i<n1 and j<n2)
    {
        if(left[i]<=right[j])
        {
            nums[k++]=left[i++];
        }
        else
        {
            res+=n1-(upper_bound(left.begin(),left.end(),(long long)2*right[j])-left.begin());
            nums[k++]=right[j++];
        }
    }
    
    while(i<n1)
    {
        nums[k++]=left[i++];
    }
    
    while(j<n2)
    {
        res+=n1-(upper_bound(left.begin(),left.end(),(long long)2*right[j])-left.begin());
        nums[k++]=right[j++];
    }
    
    return res;
}
int mergesort(vector<int>& nums,int l,int r)
{
    int cnt=0;
    if(l<r)
    {
        int mid=(l+r)>>1;
        cnt+=mergesort(nums,l,mid);
        cnt+=mergesort(nums,mid+1,r);
        cnt+=merge(nums,l,mid,r);
    }    
    return cnt;
}
int reversePairs(vector<int>& nums) 
{
    return mergesort(nums,0,nums.size()-1);
}