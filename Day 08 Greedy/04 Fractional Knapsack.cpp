//time: O(n*logn)
//space: O(1)
static bool compare(Item a,Item b)
{
    double r1=(double)a.value/a.weight;
    double r2=(double)b.value/b.weight;
    
    return r1>r2;
}
double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    //sort according to value per weight
    sort(arr,arr+n,compare);
    
    //main logic
    double amount=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i].weight<=W)
        {
            W-=arr[i].weight;
            amount+=arr[i].value;
        }
        else
        {
            amount+=arr[i].value*((double)(W)/arr[i].weight);
            break;
        }
    }
    
    return amount;
}