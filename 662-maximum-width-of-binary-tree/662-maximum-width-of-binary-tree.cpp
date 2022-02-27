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
    
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        long ans= INT_MIN;
        queue<pair<TreeNode*, int>> q;                      // with every node store its index
        
        q.push({root, 0});
        
        while(!q.empty())
        {
            long n= q.size();
            
            long firstIdx= q.front().second;                 // first idx of node in queue
            long lastIdx= q.back().second;                   // last idx of node in queue
            ans= max(ans, lastIdx-firstIdx+1);               // no. of nodes= last-first+1;
            
            while(n--)
            {
                pair<TreeNode*, long> p= q.front();  q.pop();
                TreeNode* node= p.first;
                long idx= p.second;
                
                if(node->left)
                    q.push({node->left, 2*idx+1});
                if(node->right)
                    q.push({node->right, 2*idx+2});
            }
            
        }
        return ans;
    }
};