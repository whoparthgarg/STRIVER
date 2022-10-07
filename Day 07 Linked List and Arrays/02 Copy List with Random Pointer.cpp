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

//time: O(n)
//space: O(1)
Node* copyRandomList(Node* head) {
        //part1: duplicate nodes
        Node* curr=head;
        while(curr)
        {
            Node* new_node=new Node(curr->val);
            Node* next_node=curr->next;
            new_node->next=next_node;
            curr->next=new_node;
            curr=curr->next->next;
        }
              
        //part2: change random pointers
        curr=head;
        while(curr)
        {
            if(curr->random)
            {
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }
               
        //part3: separate lists
        Node* new_head=new Node(INT_MIN);
        Node* new_curr=new_head;
        Node* fast;
        curr=head;
        while(curr)
        {
            fast=curr->next->next;
            new_curr->next=curr->next;
            curr->next=fast;
            new_curr=new_curr->next;
            curr=fast;
        }
        
        return new_head->next;
    }
