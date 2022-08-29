//time: O(n)
//space: O(1)
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    ListNode* head=new ListNode();
    ListNode* curr=head;
    int carry=0;
    
    while(l1 or l2 or carry)
    {
        int sum=0;
        
        if(l1)
        {
            sum+=l1->val;
            l1=l1->next;
        }
        
        if(l2)
        {
            sum+=l2->val;
            l2=l2->next;
        }
        
        sum+=carry;
        carry=sum/10;
        
        curr->next=new ListNode(sum%10);
        curr=curr->next;
    }
    
    return head->next;
}