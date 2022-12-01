//type 1
//time: O(n*n)
//space: O(n*n)
vector<vector<int>> generate(int n) {
        vector<vector<int>> v(n);
        
        for(int i=0;i<n;i++)
        {
            v[i].resize(i+1);
            v[i][0]=v[i][i]=1;
            for(int j=1;j<i;j++)
            {
                v[i][j]=v[i-1][j]+v[i-1][j-1];
            }
        }
        
        return v;
    }

//type 2 (naive approach)
//time: O(n*n)
//space: O(n*n)
vector<int> getRow(int n) {
        vector<vector<int>> v(n+1);
        
        for(int i=0;i<n+1;i++)
        {
            v[i].resize(i+1);
            v[i][0]=v[i][i]=1;
            for(int j=1;j<i;j++)
            {
                v[i][j]=v[i-1][j-1]+v[i-1][j];
            }
        }
                
        return v[n];
    }

//type 2 (efficient)
//time: O(n)
//space: O(n)
vector<int> getRow(int r) {
        vector<int> v(r+1,1);
        long res=1;
        
        for(int i=1;i<r;i++)
        {
            res=res*(r+1-i)/i;
            v[i]=res;
        }
        
        return v;
    }