//time: O(N*log2(M*D)) ; d:decimal places
//space: O(1)
double multiply(double number,double n)
{
	double res=1.0;
	for(int i=0;i<n;i++)
	{
		res=res*number;
	}
	
	return res;
}
double findNthRootOfM(int n, long long m)
{
	double low=1;
	double high=m;
	double eps=1e-6;
	
	while((high-low)>eps)
	{
		double mid=(low+high)/2.0;
		
		if(multiply(mid,n)<m)
		{
			low=mid;
		}
		else
		{
			high=mid;
		}
	}
	
	return low;
}