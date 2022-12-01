//super naive
//time: O(m*n*k)
//space: O(m*n)
void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> res=matrix;
        
        int m=matrix.size();
        int n=matrix[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    int row=i;
                    int col=j;
                    
                    //make row zero
                    for(int k=0;k<n;k++)
                    {
                        res[row][k]=0;
                    }
                    
                    //make col zero
                    for(int k=0;k<m;k++)
                    {
                        res[k][col]=0;
                    }
                }
            }
        }
        
        matrix=res;
    }

//naive
//time: O(m*n)
//space: O(m+n)
void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        unordered_set<int> row,col;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        
        //make row zero
        for(auto x:row)
        {
            for(int i=0;i<n;i++)
            {
                matrix[x][i]=0;
            }
        }
        
        //make col zero
        for(auto x:col)
        {
            for(int i=0;i<m;i++)
            {
                matrix[i][x]=0;
            }
        }
    }
    
//efficient
//time: O(m*n)
//space: O(1)
void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        //check first row and first col for zeros
        bool row=false,col=false;
        
        for(int i=0;i<n;i++)
        {
            if(matrix[0][i]==0)
            {
                row=true;
                break;
            }
        }
        
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]==0)
            {
                col=true;
                break;
            }
        }
        
        //check zeros in remaining matrix
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        //make matrix zeros accordingly
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][0]==0 or matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        
        if(row)
        {
            for(int i=0;i<n;i++)
            {
                matrix[0][i]=0;
            }
        }
        
        if(col)
        {
            for(int i=0;i<m;i++)
            {
                matrix[i][0]=0;
            }
        }
    }