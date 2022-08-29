//time: O(n)
//space: O(n/k)
ListNode* reverse(ListNode* head,ListNode* last)
{
    ListNode* prev=last;
    
    while(head!=last)
    {
        ListNode* nextNode=head->next;
        head->next=prev;
        prev=head;
        head=nextNode;
    }
    
    return prev;
}
ListNode* reverseKGroup(ListNode* head, int k) 
{
    ListNode* n=head;
    
    for(int i=0;i<k;i++)
    {
        //list too short
        if(n==NULL)
        {
            return head;
        }
        n=n->next;
    }
    
    auto new_head=reverse(head,n);
    head->next=reverseKGroup(n,k);
    return new_head;
}