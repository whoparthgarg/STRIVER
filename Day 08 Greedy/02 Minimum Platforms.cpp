//time: O(n*logn)
//space: O(1)
//Function to find the minimum number of platforms required at the
//railway station such that no train waits.
int findPlatform(int arr[], int dep[], int n)
{
	sort(arr,arr+n);
	sort(dep,dep+n);
	
	int res=0;
	int cnt=1;
	int i=1;
	int j=0;
	
	while(i<n and j<n)
	{
	    if(arr[i]<=dep[j])
	    {
	        i++;
	        cnt++;
	    }
	    else
	    {
	        cnt--;
	        j++;
	    }
	    res=max(cnt,res);
	}
	
	return res;
}