//type 1
//time: O(n*n)
//space: O(n*n)
vector<vector<int>> generate(int n) {
        vector<vector<int>> res(n);
        
        for(int i=0;i<n;i++)
        {
            res[i].resize(i+1);
            res[i][0]=res[i][i]=1;
            for(int j=1;j<i;j++)
            {
                res[i][j]=res[i-1][j-1]+res[i-1][j];
            }
        }
        
        return res;
    }

//type 2
//time: O(n)
//space: O(n)
vector<int> getRow(int r) {
        vector<int> v(r+1,1);
        long long res=1;
        for(int i=1;i<r;i++)
        {
            res=res*(r+1-i)/i;
            v[i]=res;
        }
        
        return v;
    }