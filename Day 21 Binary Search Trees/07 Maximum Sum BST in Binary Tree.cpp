//tle code
//time: O(n*n)
//space: O(n)
class Solution {
public:
    int sum(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        return (root->val+sum(root->left)+sum(root->right));
    }
    bool validate(TreeNode* root,int mini,int maxi)
    {
        if(root==NULL)
        {
            return true;
        }
        
        if(root->val>mini and root->val<maxi)
        {
            return validate(root->left,mini,root->val) and validate(root->right,root->val,maxi);
        }
        
        return false;
    }
    int maxSumBST(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int max_sum=0;
        while(q.size())
        {
            TreeNode* node=q.front();
            q.pop();
            
            int mini=INT_MIN;
            int maxi=INT_MAX;
            if(validate(node,mini,maxi))
            {
                max_sum=max(max_sum,sum(node));
            }
            
            if(node->left)
            {
                q.push(node->left);
            }
            
            if(node->right)
            {
                q.push(node->right);
            }
        }
        
        return max_sum;
    }
};

//optimised
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // {smallest_num, largest_num, curr_sum} of a tree
    vector<int> traverse(TreeNode* root, int& ans) {
        if (!root) return {INT_MAX, INT_MIN, 0};
        vector<int> left(traverse(root->left, ans)), right(traverse(root->right, ans));
        // check if a tree is BST
        if (left.empty() || right.empty() || root->val <= left[1] || root->val >= right[0]) return {};
        // if BST, update ans
        int curr_sum = left[2] + right[2] + root->val;
        ans = max(ans, curr_sum);
        return {min(left[0], root->val), max(right[1], root->val), curr_sum};
    }
    int maxSumBST(TreeNode* root) {
        int ans(0);
        traverse(root, ans);
        return max(0, ans);
    }
};