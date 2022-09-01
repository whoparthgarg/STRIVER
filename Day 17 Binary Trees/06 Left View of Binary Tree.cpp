//time: O(n)
//space: O(n)
vector<int> leftView(Node *root)
{
	if(root==NULL)
	{
	    return {};
	}
	vector<int> v;

	queue<Node*> q;
	q.push(root);

	while(q.size())
	{
	   int n=q.size();
	   
	   for(int i=0;i<n;i++)
	   {
	       if(i==0)
	       {
	           v.push_back(q.front()->data);
	       }
	       Node* temp=q.front();
	       q.pop();
	       
	       if(temp->left)
	       {
	           q.push(temp->left);
	       }
	       
	       if(temp->right)
	       {
	           q.push(temp->right);
	       }
	   }
	}

	return v;
}
