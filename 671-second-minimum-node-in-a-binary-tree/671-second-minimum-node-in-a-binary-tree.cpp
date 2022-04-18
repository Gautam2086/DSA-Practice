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
    int min;
    int ans = INT_MAX;
    int ans_found = false; // Needed this because INT_MAX can also be the answer 
    //[2,2,2147483647] => c++ INT_MAX value => 2147483647
    
    void traverse(TreeNode* root) {
        if (root == NULL) return;
        if (min < root->val && root->val <= ans) {
            ans = root->val;
            ans_found = true;
        } else if (root->val == min) {
            traverse(root->left);
            traverse(root->right);
        }
        return;
    }
    int findSecondMinimumValue(TreeNode* root) {
        if (root == NULL) return -1;
        if (root->left == NULL) return -1; 
        // From question this implies root->right will also be equal to NULL
        min = root->val;
        traverse(root);
        return ans_found ? ans : -1;
    }
};