//time: O(n)
//space: O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
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
            vector<int> temp;
            for(int i=0;i<n;i++)
            {
                TreeNode* nn=q.front();
                q.pop();
                temp.push_back(nn->val);
                
                if(nn->left)
                {
                    q.push(nn->left);
                }
                
                if(nn->right)
                {
                    q.push(nn->right);
                }
            }
            res.push_back(temp);
        }
        
        return res;
    }
    

};