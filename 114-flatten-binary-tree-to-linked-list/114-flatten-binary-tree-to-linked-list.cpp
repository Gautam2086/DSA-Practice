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
    
    void preorder(TreeNode* root, vector<TreeNode*>& v) {
        if(!root)   return; 
    
        v.push_back(root);
        preorder(root->left, v);
        preorder(root->right, v);
        return;
    }
    
    void flatten(TreeNode* root) {
        if(!root)   return;
        
        vector<TreeNode*> v;
        preorder(root, v);
        
        TreeNode* tmp= root;
        
        for(int i=1; i<v.size(); i++) {
            tmp->left= NULL;
            tmp->right= v[i];
            tmp= tmp->right;
        }
        
    }
};