//two traversal
//time: O(n)
//space: O(1)
void sortColors(vector<int>& nums) {
        int n=nums.size();
        int c0=0,c1=0,c2=0;
        
        for(auto x:nums)
        {
            if(x==0)
            {
                c0++;
            }
            else if(x==1)
            {
                c1++;
            }
            else
            {
                c2++;
            }
        }
        
        c1+=c0;
        c2+=c1;
        for(int i=0;i<n;i++)
        {
            if(i<c0)
            {
                nums[i]=0;
            }
            else if(i<c1)
            {
                nums[i]=1;
            }
            else if(i<c2)
            {
                nums[i]=2;
            }
        }
    }


//one traversal
//time: O(n)
//space: O(1)
void sortColors(vector<int>& nums) 
{
    int n=nums.size();
    
    int low=0;
    int mid=0;
    int high=n-1;
    
    while(mid<=high)
    {
        if(nums[mid]==0)
        {
            swap(nums[low++],nums[mid++]);
        }
        else if(nums[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid],nums[high--]);
        }
    }
}