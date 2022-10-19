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
            Node* newNode=new Node(curr->val);
            Node* nextNode=curr->next;
            newNode->next=nextNode;
            curr->next=newNode;
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
        
        //part3: separate list
        Node* newHead=new Node(INT_MIN);
        Node* newCurr=newHead;
        Node* fast;
        curr=head;
        while(curr)
        {
            fast=curr->next->next;
            newCurr->next=curr->next;
            curr->next=fast;
            newCurr=newCurr->next;
            curr=fast;
        }
        
        return newHead->next;
    }
