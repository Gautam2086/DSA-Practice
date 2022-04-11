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
    void preorder(TreeNode* root, vector<int>& v) {
        if(root == NULL)
            return;
        v.push_back(root->val);
        preorder(root->left, v);
        preorder(root->right, v);
        
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL)
            return 0;
        vector<int> v;
        preorder(root, v);
        sort(v.begin(), v.end());
        return v[k-1];
    }
};