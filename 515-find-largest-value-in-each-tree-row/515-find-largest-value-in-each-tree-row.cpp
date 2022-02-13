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
    vector<int> largestValues(TreeNode* root) {
        
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int s= q.size();
            int mx= INT_MIN;
            while(s--)                                  // at each level
            {
                TreeNode* curr= q.front();  q.pop();
                mx= max(mx, curr->val);                // check for greatest max at each level
                    
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};