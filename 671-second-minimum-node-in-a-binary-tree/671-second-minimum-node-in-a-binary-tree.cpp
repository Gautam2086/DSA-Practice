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
    
    void inorder(TreeNode* root, set<int>& s) {
        if(!root)   return;
        
        inorder(root->left, s);
        s.insert(root->val);
        inorder(root->right, s);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        vector<int> v;
        
        inorder(root, s);
        
        if(s.size() < 2) 
            return -1;
        
        for(auto x: s) {
            v.push_back(x);
        }
        sort(v.begin(), v.end());
    
        return v[1];
    }
};