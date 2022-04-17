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
    void inOrder(TreeNode* root, vector<int> &v) {
        if(root==NULL)
            return;
        
        inOrder(root->left, v);
        v.push_back(root->val);
        inOrder(root->right, v);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> v;
        inOrder(root, v);
        
        TreeNode* head= new TreeNode(v[0]);
        TreeNode* tmp= head;
        
        for(int i=1; i<v.size(); i++) {
            tmp->right= new TreeNode(v[i]);
            tmp= tmp->right;
        }
        
        return head;
    }
};