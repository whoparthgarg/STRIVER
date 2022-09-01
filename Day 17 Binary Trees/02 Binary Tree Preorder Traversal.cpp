//time: O()
//space: O()
class Solution {
public:
    vector<int> v;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL)
        {
            return {};
        }
        
        //root left right
        v.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return v;
    }
};