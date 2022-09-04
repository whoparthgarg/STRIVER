//time: O(n)
//space: O(n)
vector<vector<int>> levelOrder(TreeNode* root) 
{
    vector<vector<int>> res;
    if(root==NULL)
    {
        return res; 
    }
    
    queue<TreeNode*> q;
    q.push(root);
    
    while(q.size())
    {
        int n=q.size();
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            TreeNode* node=q.front();
            q.pop();
            
            if(node->left)
            {
                q.push(node->left);
            }
            
            if(node->right)
            {
                q.push(node->right);
            }
            
            v.push_back(node->val);
        }
        res.push_back(v);
    }
    
    return res;
}