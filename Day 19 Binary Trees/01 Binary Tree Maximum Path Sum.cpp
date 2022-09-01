//time: O(n)
//space: O(n)
class Solution {
public:
    int max_sum=INT_MIN;
    int max_gain(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int l=max(max_gain(root->left),0);
        int r=max(max_gain(root->right),0);
        int curr_max=root->val+l+r;
        max_sum=max(max_sum,curr_max);
        
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        max_gain(root);
        return max_sum;
    }
};