//time: O(n)
//space: O(1)
ListNode* rotateRight(ListNode* head, int k) 
{
    // base cases
    if(head==NULL or head->next==NULL or k==0)
    {
        return head;
    }
    
    // find length and tail
    ListNode* tail=head;
    int len=1;
    while(tail->next)
    {
        tail=tail->next;
        len++;
    }
    
    // remove extra iterations
    k=k%len;
    
    // make loop in the list
    tail->next=head;
    
    // find new head of linked list
    int i=len-k;
    while(i--)
    {
        tail=tail->next;
    }
    
    // making new head
    head=tail->next;
    tail->next=NULL;
    
    return head;
}