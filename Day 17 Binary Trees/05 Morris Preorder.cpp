class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        
        if(root==NULL)
        {
            return v;
        }
        
        stack<TreeNode*> st;
        st.push(root);
        
        while(st.size())
        {
            TreeNode* node=st.top();
            st.pop();
            
            if(node->right)
            {
                st.push(node->right);
            }
            
            if(node->left)
            {
                st.push(node->left);
            }            
            
            v.push_back(node->val);
        }
        
        return v;
    }
};