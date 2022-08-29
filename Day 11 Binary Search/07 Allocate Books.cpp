//time: O(n*logn)
//space: O(1)
bool isPossible(vector<int> &nums,int pages,int S){
    int n=nums.size();
    int cnt=0;
    int sum_allocated=0;

    for(int i=0;i<n;i++)
    {
        if(sum_allocated+nums[i]>pages)
        {
            cnt++;
            sum_allocated=nums[i];
            if(sum_allocated>pages)
            {
                return false;
            }
        }
        else
        {
            sum_allocated+=nums[i];
        }
    }

    if(cnt<S)
    {
        return true;
    }

    return false;
}
int Solution::books(vector<int> &nums, int S) {
    int n=nums.size();

    //books should be greater than equal to students
    if(S>n)
    {
        return -1;
    }

    //find search space
    int low=INT_MAX;
    int high=0;
    for(auto x:nums)
    {
        low=min(low,x);
        high+=x;
    }

    //apply binary search
    while(low<=high)
    {
        int mid=(low+high)/2;

        if(isPossible(nums,mid,S))
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }

    return low;
}