//time: O(n*logn)
//space: O(n)
long long merge(long long *a,int l,int m,int r)
{
    int n1=m+1-l;
    int n2=r-m;
    
    int left[n1];
    int right[n2];
    
    for(int i=0;i<n1;i++)
    {
        left[i]=a[l+i];
    }
    
    for(int j=0;j<n2;j++)
    {
        right[j]=a[m+1+j];
    }
    
    int i=0;
    int j=0;
    int k=l;
    int res=0;
    
    while(i<n1 and j<n2)
    {
        if(left[i]<=right[j])
        {
            a[k++]=left[i++];
        }
        else
        {
            a[k++]=right[j++];
            res+=n1-i;
        }
    }
    
    while(i<n1)
    {
        a[k++]=left[i++];
    }
    
    while(j<n2)
    {
        a[k++]=right[j++];
    }
    
    return res;
}
long long mergesort(long long *arr,int l,int r)
{
    int cnt=0;
    
    if(l<r)
    {
        int m=(l+r)>>1;
        cnt+=mergesort(arr,l,m);
        cnt+=mergesort(arr,m+1,r);
        cnt+=merge(arr,l,m,r);
    }
    
    return cnt;
}
long long getInversions(long long *arr, int n){
    return mergesort(arr,0,n-1);
}