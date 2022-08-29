//time: O(n)
//space: O(n)
int lengthOfLongestSubstring(string s) 
{
    int n=s.size();
    int i=0;
    int j=0;
    int maxlen=0;
    
    unordered_set<char> set;    
    while(i<n and j<n)
    {
        if(set.find(s[j])==set.end())
        {
            set.insert(s[j++]);
            maxlen=max(maxlen,j-i);
        }
        else
        {
            set.erase(s[i++]);
        }
    }
    
    return maxlen;
}