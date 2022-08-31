//time: O(h)
//space: O(n)
class Solution
{
    public:
    vector<int> v;
    void inorder(Node* root)
    {
        if(root==NULL)
        {
            return ;
        }
        
        //left root right
        inorder(root->left);
        v.push_back(root->data);
        inorder(root->right);
    }
    int kthLargest(Node *root, int k)
    {
        inorder(root);
        return v[v.size()-k];
    }
};

//time: O(h)
//space: O(h)
int res;
void solve(Node* root,int k,int &cnt)
{
    if(root==NULL or cnt>=k)
    {
        return ;
    }
    
    //reverse inorder travesal approach
    //right root left
    solve(root->right,k,cnt);
    cnt++;
    if(cnt==k)
    {
        res=root->data;
        return ;
    }
    solve(root->left,k,cnt);
}
int kthLargest(Node *root, int k)
{
    int cnt=0;
    solve(root,k,cnt);
    return res;
}