//naive
//time: O(m*n)
//space: O(m+n)
void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        unordered_set<int> row;
        unordered_set<int> col;
        
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
        
        for(auto x:row)
        {
            for(int j=0;j<n;j++)
            {
                matrix[x][j]=0;
            }
        }
        
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
        
        bool row=false;
        bool col=false;
        
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