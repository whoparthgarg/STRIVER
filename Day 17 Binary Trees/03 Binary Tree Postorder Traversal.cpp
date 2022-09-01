//time: O()
//space: O()
class Solution {
public:
    vector<int> v;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL)
        {
            return {};
        }
        
        //left right root
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        v.push_back(root->val);
        return v;
    }
};