//time: O()
//space: O()
bool ispalindrome(string s,int i,int j)
{
    while(i<j)
    {
        if(s[i]!=s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    
    return true;
}
void solve(string s,int i,vector<string> &temp,vector<vector<string>> &res)
{
    if(i==s.size())
    {
        res.push_back(temp);
        return ;
    }
    
    for(int j=i;j<s.size();j++)
    {
        if(ispalindrome(s,i,j))
        {
            temp.push_back(s.substr(i,j-i+1));
            solve(s,j+1,temp,res);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> temp;
    solve(s,0,temp,res);
    return res;
}