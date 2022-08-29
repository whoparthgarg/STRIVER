//time: O(n)
//space: O(1)
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
    ListNode* head=new ListNode();
    ListNode* curr=head;
    
    while(l1 and l2)
    {
        if(l1->val<=l2->val)
        {
            curr->next=l1;
            l1=l1->next;
        }
        else
        {
            curr->next=l2;
            l2=l2->next;
        }
        curr=curr->next;
    }
    
    curr->next=l1?l1:l2;
    
    return head->next;
}