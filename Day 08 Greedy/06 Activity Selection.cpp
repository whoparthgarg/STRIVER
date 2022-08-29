//time: O(n*logn)
//space: O(n)
int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        v.push_back({end[i],start[i]});
    }
    
    sort(v.begin(),v.end());
    
    int maxm=1;
    int prev=0;
    
    for(int i=1;i<n;i++)
    {
        if(v[i].second>v[prev].first)
        {
            prev=i;
            maxm++;
        }
    }
    
    return maxm;
}