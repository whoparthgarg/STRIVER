//time: O(n)
//space: O(n)
vector<int> bottomView(Node *root) 
{
    vector<int> res;
    map<int,int> m;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    
    while(q.size())
    {
        auto temp=q.front();
        q.pop();
        
        Node* node=temp.first;
        int level=temp.second;
        m[level]=node->data;
        
        if(node->left)
        {
            q.push({node->left,level-1});
        }
        if(node->right)
        {
            q.push({node->right,level+1});
        }
    }
    
    for(auto x:m)
    {
        res.push_back(x.second);
    }
    
    return res;
}