//time: O(n)
//space: O(1)
class Solution {
public:
    void flatten(TreeNode* root) {
        while(root)
        {
            if(root->left and root->right)
            {
                TreeNode* temp=root->left;
                while(temp->right)
                {
                    temp=temp->right;
                }
                temp->right=root->right;
            }
            
            if(root->left)
            {
                root->right=root->left;
            }
            root->left=NULL;
            root=root->right;
        }
    }
};