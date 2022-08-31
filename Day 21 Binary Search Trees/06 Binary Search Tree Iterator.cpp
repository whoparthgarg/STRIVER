//naive approach
//time: O(1)
//space: O(N)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<int> v;
    int pt=0;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
        {
            return ;
        }
        
        //left root right
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        if(pt>=v.size())
        {
            return -1;
        }
        
        int res=v[pt];
        pt++;
        return res;
    }
    
    bool hasNext() {
        if(pt>=v.size())
        {
            return false;
        }
        
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

//efficient
//time: O(1)
//space: O(h)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> st;
    void pushNodes(TreeNode* root)
    {
        while(root)
        {
            st.push(root);
            root=root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushNodes(root);
    }
    
    int next() {
        TreeNode* node=st.top();
        st.pop();
        pushNodes(node->right);
        return node->val;
    }
    
    bool hasNext() {
        if(st.empty()==true)
        {
            return false;
        }
        
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */