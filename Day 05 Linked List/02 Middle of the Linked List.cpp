//time: O(n)
//space: O(1)
ListNode* middleNode(ListNode* head) 
{
    ListNode* slow=head;
    ListNode* fast=head;
    
    while(slow and fast and fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    
    return slow;
}