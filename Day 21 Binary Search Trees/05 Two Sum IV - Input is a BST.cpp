//time: O(n)
//space: O(n)
class Solution {
public:
    vector<int> v;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL)
        {
            return {};
        }
        
        //left root right
        inorderTraversal(root->left);
        v.push_back(root->val);
        inorderTraversal(root->right);
        
        return v;
    }
    bool twoSum(vector<int>& v,int k)
    {
        int i=0;
        int j=v.size()-1;
        
        while(i<j)
        {
            int sum=v[i]+v[j];
            if(sum==k)
            {
                return true;
            }
            else if(sum>k)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        
        return false;
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> ve(inorderTraversal(root));
        return twoSum(ve,k);
    }
    
};

//time: O(n)
//space: O(n)
unordered_set<int> s;
bool findTarget(TreeNode* root, int sum) {
    if(root==NULL)
    {
        return false;
    }
    
    if(s.find(sum-root->val)!=s.end())
    {
        return true;
    }
    
    s.insert(root->val);
    
    return findTarget(root->left,sum) or findTarget(root->right,sum);
}