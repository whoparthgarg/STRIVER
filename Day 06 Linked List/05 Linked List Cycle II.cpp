//time: O(n)
//space: O(1)
ListNode *detectCycle(ListNode *head) 
{
    ListNode* slow=head;
    ListNode* fast=head;
    
    while(slow and fast and fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            fast=head;
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
            
            return fast;
        }
    }
    
    return NULL;
}