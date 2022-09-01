//time: O(n)
//space: O(n)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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
                temp.push_back(node->val);
            }
            res.push_back(temp);
        }
        
        for(int i=0;i<res.size();i++)
        {
            if(i%2==1)
            {
                reverse(res[i].begin(),res[i].end());
            }
        }
        
        return res;
    }
};