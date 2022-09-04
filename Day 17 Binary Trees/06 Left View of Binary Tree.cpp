//time: O(n)
//space: O(n)
vector<int> leftView(Node *root)
{
   vector<int> res;
   if(root==NULL)
   {
       return res;
   }
   
   queue<Node*> q;
   q.push(root);
   
   while(q.size())
   {
       int n=q.size();
       for(int i=0;i<n;i++)
       {
           Node* node=q.front();
           q.pop();
           
           if(i==0)
           {
               res.push_back(node->data);
           }
           
           if(node->left)
           {
               q.push(node->left);
           }
           
           if(node->right)
           {
               q.push(node->right);
           }
       }
   }
   
   return res;
}