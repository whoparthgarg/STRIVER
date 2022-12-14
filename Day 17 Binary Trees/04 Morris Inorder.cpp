class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        
        stack<TreeNode*> st;
        TreeNode* node=root;
        
        while(true)
        {
            if(node)
            {
                st.push(node);
                node=node->left;
            }
            else
            {
                if(st.empty())
                {
                    return v;
                }
                node=st.top();
                st.pop();
                v.push_back(node->val);
                node=node->right;
            }
        }
        
        return v;
    }
};