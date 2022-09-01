class Solution {
public:
    unordered_map<int,int> m;
    TreeNode* maketree(int start,int end,int &idx,vector<int>& postorder,vector<int>& inorder)
    {
        if(start>end)
        {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(postorder[idx]);
        
        int i = m[root->val];
        idx--;
		
        root->right = maketree(i+1, end, idx, postorder, inorder);
        root->left = maketree(start, i-1, idx, postorder, inorder);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx=postorder.size()-1;
        
        for(int i=0;i<inorder.size();i++)
        {
            m[inorder[i]]=i;
        }
        
        return maketree(0,inorder.size()-1,idx,postorder,inorder);
    }
};