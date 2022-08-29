//time: O(1)
//space: O(1)
void deleteNode(ListNode* node) 
{
        node->val=node->next->val;
        node->next=node->next->next;
}