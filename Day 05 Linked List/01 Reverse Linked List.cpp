//iterative
//time: O(n)
//space: O(1)
ListNode* reverseList(ListNode* head) 
{
    ListNode* prev=NULL;
    
    while(head)
    {
        ListNode* nextNode=head->next;
        head->next=prev;
        prev=head;
        head=nextNode;
    }
    
    return prev;
}

//reverse
//time: O(n)
//space: O(n)
ListNode* reverseList(ListNode* head) 
{
    if(head==NULL or head->next==NULL)
    {
        return head;
    }
    
    ListNode* newHead=reverseList(head->next);
    head->next->next=head;
    head->next=NULL;
    
    return newHead;
}
