//time: O(n*m)
//space: O(1)
Node *merge(Node* l1,Node* l2)
{
    Node* head=new Node(0);
    Node* curr=head;
    
    while(l1 and l2)
    {
        if(l1->data<=l2->data)
        {
            curr->bottom=l1;
            l1=l1->bottom;
        }
        else
        {
            curr->bottom=l2;
            l2=l2->bottom;
        }
        curr=curr->bottom;
    }
    
    curr->bottom=l1?l1:l2;
    return head->bottom;
}
Node *flatten(Node *root)
{
   if(root==NULL or root->next==NULL)
   {
       return root;
   }
   
   // reach at end of last node
   root->next=flatten(root->next);
   
   // merge all nodes
   root=merge(root,root->next);
   
   return root;
}