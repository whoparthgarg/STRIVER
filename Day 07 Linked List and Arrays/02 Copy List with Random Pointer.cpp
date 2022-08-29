//time: O(n)
//space: O(n)
Node* copyRandomList(Node* head) 
{
    unordered_map<Node*,Node*> m;

    Node* curr=head;
    while(curr)
    {
	    m[curr]=new Node(curr->val);
	    curr=curr->next;
    }

    curr=head;
    while(curr)
    {
	    Node* temp=m[curr];
	    temp->next=m[curr->next];
	    temp->random=m[curr->random];
	    curr=curr->next;
    }
    Node* res=m[head];

    return res;
}