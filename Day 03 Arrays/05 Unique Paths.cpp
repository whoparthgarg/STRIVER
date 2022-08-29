//brute force 
//time: O(2^n)
//space: O(1)
int countPath(int i,int j,int m,int n)
{
    if(i==m and j==n)
    {
        return 1;
    }
    
    if(i>m or j>n)
    {
        return 0;
    }
    else
    {
        return (countPath(i+1,j,m,n)+countPath(i,j+1,m,n));
    }
}
int uniquePaths(int m, int n) 
{
    return countPath(0,0,m-1,n-1);
}

//optimal 
//time: O(m*n)
//space: O(m*n)
int dp[101][101];
int countPath(int i,int j,int m,int n)
{
    if(dp[i][j]==-1)
    {
        if(i==m and j==n)
        {
            return dp[i][j]=1;
        }
    
        if(i>m or j>n)
        {
            return dp[i][j]=0;
        }
        else
        {
            return dp[i][j]=(countPath(i+1,j,m,n)+countPath(i,j+1,m,n));
        }
    }
    
    return dp[i][j];
}
int uniquePaths(int m, int n) 
{
    memset(dp,-1,sizeof(dp));
    return countPath(0,0,m-1,n-1);
}

//optimised
//time: O(m*n)
//space: O(m*n)
int uniquePaths(int m, int n) 
{
    vector<vector<int>> dp(m,vector<int> (n,1));
    
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    
    return dp[m-1][n-1];
}

//optimal 
//time: O(n)
//space: O(1)
int uniquePaths(int m, int n) 
{
    int N=n+m-2;
    int r=m-1;
    double res=1;
    
    for(int i=1;i<=r;i++)
    {
        res=res*(N-r+i)/i;
    }
    
    return res;
}