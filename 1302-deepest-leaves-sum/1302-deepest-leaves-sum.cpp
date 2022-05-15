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
    int ans= INT_MIN;                           // to find max depth
    int sum= 0;                                 // to find sum of values at max depth
    
    void helper(TreeNode* root, int depth) {
        if(!root)   return;
        
        if(!root->left && !root->right)
            ans= max(depth, ans);
        
        if(root->left)
            helper(root->left, depth+1);
        if(root->right)
            helper(root->right, depth+1);
    }
    
    void deepestSum(TreeNode* root, int depth) {
        if(!root)
            return;
            
        if(depth == ans)
            sum += root->val;
        
        if(root->left)
            deepestSum(root->left, depth+1);
        if(root->right)
            deepestSum(root->right, depth+1);
        
    }
    int deepestLeavesSum(TreeNode* root) {
        
        helper(root, 1);                     // to find max depth
        
        deepestSum(root, 1);                 // to find sum of values at max depth
        return sum;
    }
};