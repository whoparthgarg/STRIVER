//time: O(logn)
//space: O(1)
double myPow(double x, int n) 
{
    double res=1;
    long nn=abs(n);
    
    while(nn)
    {
        if(nn%2==0)
        {
            x=x*x;
            nn=nn/2;
        }
        else
        {
            res=res*x;
            nn--;
        }
    }
    
    if(n<0)
    {
        return (1/res);
    }
    
    return res;
}