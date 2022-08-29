//time: O(m+n)
//space: O(1)
bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int m=matrix.size();
    int n=matrix[0].size();
    
    int i=0;
    int j=n-1;
    
    while(i<m and j>=0)
    {
        int e=matrix[i][j];
        
        if(e==target)
        {
            return true;
        }
        else if(e>target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    
    return false;
}

//time: O(logm+logn)
//space: O(1)
bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int m=matrix.size();
    int n=matrix[0].size();
    
    //first find row
    int low=0;
    int high=m-1;
    while(low<high)
    {
        int mid=(low+high)>>1;
        
        if(matrix[mid][0]==target)
        {
            return true;
        }
        
        if(matrix[mid][0]<target and target<matrix[mid+1][0])
        {
            low=mid;
            break;
        }
        else if(matrix[mid][0]<target)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    
    //find col
    int row=low;
    low=0;
    high=n-1;
    
    while(low<=high)
    {
        int mid=(low+high)>>1;
        
        if(matrix[row][mid]==target)
        {
            return true;
        }
        else if(matrix[row][mid]>target)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    
    return false;
}