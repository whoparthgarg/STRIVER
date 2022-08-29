//time: O(n)
//space: O(1)
int maxProfit(vector<int>& prices) 
{
    int n=prices.size();
    int min_val=INT_MAX;
    int max_profit=0;
    
    for(auto x:prices)
    {
        min_val=min(min_val,x);
        max_profit=max(max_profit,x-min_val);
    }
    
    return max_profit;
}