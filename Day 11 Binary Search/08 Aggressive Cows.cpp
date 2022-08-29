//time: O(n*logn)
//space: O(1)
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &nums,int d,int c)
{
    int n=nums.size();
    int cnt_cows=1;
    int last_cow_placed=nums[0];
    
    for(int i=1;i<n;i++)
    {
        if(nums[i]-last_cow_placed>=d)
        {
            cnt_cows++;
            last_cow_placed=nums[i];
        }
    }
    
    if(cnt_cows>=c)
    {
        return true;
    }
    
    return false;
}

int aggressiveCows(vector<int> &nums,int c)
{
    int n=nums.size();
    sort(nums.begin(),nums.end());
    
    int low=1;
    int high=nums[n-1]-nums[0];
    
    while(low<=high)
    {
        int mid=(low+high)/2;
        
        if(isPossible(nums,mid,c))
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    
    return high;
}

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
    
        int c;
        cin>>c;
    
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            int no;
            cin>>no;
            v.push_back(no);
        }
        
        cout<<aggressiveCows(v,c)<<endl;
    }
    
    return 0;
}