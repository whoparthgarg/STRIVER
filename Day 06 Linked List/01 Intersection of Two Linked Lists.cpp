//time: O(n)
//space: O(1)
ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) 
{
    ListNode* p1=l1;
    ListNode* p2=l2;
    
    while(p1 and p2 and p1!=p2)
    {
        p1=p1->next;
        p2=p2->next;
        
        if(p1==p2)
        {
            return p1;
        }
        
        if(p1==NULL)
        {
            p1=l2;
        }
        
        if(p2==NULL)
        {
            p2=l1;
        }
    }
    
    return p1;
}