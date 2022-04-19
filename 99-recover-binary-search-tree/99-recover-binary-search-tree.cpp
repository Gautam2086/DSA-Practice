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
    int i= 0;
    void inorder(TreeNode* root, vector<int> &v) {
        if(!root)   return;
        
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
        return;
    }
    
    void swapNodes(TreeNode* root, vector<int>& v) {
        if(!root)   return;
        
        swapNodes(root->left, v);
        
        if(v[i] != root->val)
            swap(root->val, v[i]);
        i++;
        
        swapNodes(root->right, v);
    }
    
    void recoverTree(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        
        sort(v.begin(), v.end());
        swapNodes(root, v);
    }
};