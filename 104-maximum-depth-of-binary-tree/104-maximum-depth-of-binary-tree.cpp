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
class Solution {
public:
    int ans= INT_MIN;
    
    void helper(TreeNode* root, int depth) {
        if(!root)   return;
        
        if(!root->left && !root->right)
            ans= max(depth, ans);
        
        if(root->left)
            helper(root->left, depth+1);
        if(root->right)
            helper(root->right, depth+1);
        
    }
    
    
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        helper(root, 1);
        return ans;
    }
};