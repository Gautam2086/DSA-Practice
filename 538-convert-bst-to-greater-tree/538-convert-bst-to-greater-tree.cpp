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
    // apply inorder traversal in reverse direction and caclucate accumuated sum til now
    
    int accSum= 0;
    
    void modifiedInorder(TreeNode* root) {
        if(!root)   return;
        
        modifiedInorder(root->right);
        
        root->val += accSum;
        accSum = root->val;
        
        modifiedInorder(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        modifiedInorder(root);
        
        return root;
    }
};