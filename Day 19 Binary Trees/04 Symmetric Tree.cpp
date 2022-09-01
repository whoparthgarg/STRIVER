//time: O(n)
//space: O(n)
class Solution {
public:
    bool check(TreeNode* r1,TreeNode* r2)
    {
        if(r1==NULL and r2==NULL)
        {
            return true;
        }
        
        if(r1==NULL or r2==NULL)
        {
            return false;
        }
        
        if(r1->val!=r2->val)
        {
            return false;
        }
        
        return (check(r1->right,r2->left) and check(r1->left,r2->right));
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        
        return check(root->left,root->right);
    }
};