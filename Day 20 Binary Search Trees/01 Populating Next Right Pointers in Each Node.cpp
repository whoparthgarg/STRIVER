//time: O(n)
//space: O(n)
Node* connect(Node* root) 
{
    if(root==NULL)
    {
        return root;
    }
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(q.size())
    {
        Node* n=q.front();
        q.pop();
        
        if(n)
        {
            n->next=q.front();
            
            if(n->left)
            {
                q.push(n->left);
            }
            if(n->right)
            {
                q.push(n->right);
            }
        }
        else if(q.empty()==false)
        {
            q.push(NULL);
        }
    }
    
    return root;
}