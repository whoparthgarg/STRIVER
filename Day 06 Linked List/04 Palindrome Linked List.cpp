//time: O(n)
//space: O(1)
ListNode* reverse(ListNode* head)
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
bool isPalindrome(ListNode* head) 
{
    //get middle and then reverse part
    //after middle and then compare the
    //head and part after mid next
    ListNode* slow=head;
    ListNode* fast=head;
    
    while(fast and fast->next and fast->next->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    
    //this step for odd linked list
    //ignore the middle element in
    //odd length linked list
    slow->next=reverse(slow->next);
    slow=slow->next;
    fast=head;
    
    while(slow)
    {
        if(slow->val!=fast->val)
        {
            return false;
        }
        slow=slow->next;
        fast=fast->next;
    }
    
    return true;
}