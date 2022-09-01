//time: O(n)
//space: O(n)
class Solution {
public:
    int height(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        return (1+max(height(root->left),height(root->right)));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        
        int lh=height(root->left);
        int rh=height(root->right);
        
        return (abs(lh-rh)<=1 and isBalanced(root->left) and isBalanced(root->right));
    }
};