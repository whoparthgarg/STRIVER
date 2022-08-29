//time: O(n*n)
//space: O(1)
void rotate(vector<vector<int>>& matrix) 
{
    int n=matrix.size();
    
    //transpose
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i<j)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    
    //reverse each row
    for(int i=0;i<n;i++)
    {
        reverse(matrix[i].begin(),matrix[i].end());
    }
}