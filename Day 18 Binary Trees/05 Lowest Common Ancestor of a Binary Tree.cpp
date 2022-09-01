//time: O(n)
//space: O(n)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL or p==root or q==root)
        {
            return root;
        }
        
        auto left=lowestCommonAncestor(root->left,p,q);
        auto right=lowestCommonAncestor(root->right,p,q);
        
        if(left and right)
        {
            return root;
        }
        else
        {
            return left?left:right;
        }
    }
};
