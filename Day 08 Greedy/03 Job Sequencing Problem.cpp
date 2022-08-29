//time: O(n*n)
//space: O(n)
static bool compare(Job a,Job b)
{
    return a.profit>b.profit;
}
vector<int> JobScheduling(Job arr[], int n) 
{ 
    //sort in order of decreasing profit
    sort(arr,arr+n,compare);
    
    //find maximum deadline
    int maxi=arr[0].dead;
    for(int i=1;i<n;i++)
    {
        maxi=max(maxi,arr[i].dead);
    }
    
    //track activities
    int slot[maxi+1];
    memset(slot,-1,sizeof(slot));
    
    //res variables
    int jobs=0;
    int profit=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=arr[i].dead;j>0;j--)
        {
            if(slot[j]==-1)
            {
                slot[j]=i;
                jobs++;
                profit+=arr[i].profit;
                break;
            }
        }
    }
    
    return {jobs,profit};
} 