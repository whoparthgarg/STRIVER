//time: O(n*logn)
//space: O(1)
int minCoins(int coins[],int n,int amount)
{
    sort(coins,coins+n);

    int res=0;
    for(int i=n-1;i>=0;i--)
    {
        if(coins[i]<=amount)
        {
            int number_of_coins=floor(amount/coins[i]);
            res+=number_of_coins;
            amount=amount-number_of_coins*coins[i];
        }
    }

    return res;
}