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
    int ans= 0;
    int count= 0;
    void inorder(TreeNode* root, vector<int>& v, int k) {
        if(root == NULL)
            return;
        
        inorder(root->left, v, k);
        v.push_back(root->val);     count++; 
        
        if(count==k) {
            ans= root->val;
            return;
        }
        
        inorder(root->right, v, k);
        
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL)
            return 0;
        
        vector<int> v;
        inorder(root, v, k);
        
        return ans;
    }
};