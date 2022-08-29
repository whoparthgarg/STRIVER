//time: O(32*N*log2(M))
//space: O(1)
int countSmaller(vector<int> nums,int x)
{
    int n=nums.size();
    int low=0;
    int high=n-1;
    
    while(low<=high)
    {
        int mid=(low+high)>>1;
        
        if(nums[mid]<=x)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    
    return low;
}
int Solution::findMedian(vector<vector<int> > &mat) {
    int row=mat.size();
    int col=mat[0].size();
    
    int low=1;
    int high=1e9;
    
    int desired_count=(row*col)/2;    
    while(low<=high)
    {
        int mid=(low+high)/2;
        
        int cnt=0;//<=mid
        for(int i=0;i<row;i++)
        {
            cnt+=countSmaller(mat[i],mid);
        }
        
        if(cnt<=desired_count)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    
    return low;
}