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
    // static bool cmp(pair<int,int>& p1, pair<int,int>& p2) { 
    //     return (p1.first<p2.first); 
    // };
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> res;
        map<int, vector<int>> mp;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(!q.empty())
        {
            int size= q.size();
            vector<pair<int,int>> v;
            while(size--)
            {
                auto p= q.front();  q.pop();
                int dis= p.second;
                auto node= p.first;

                v.push_back({node->val, dis});

                if(node->left) {
                    q.push({node->left, dis-1});
                }
                if(node->right) {
                    q.push({node->right, dis+1});
                }
            }
            sort(v.begin(), v.end());
            for(int i=0; i<v.size(); i++) 
                mp[v[i].second].push_back(v[i].first);
            
        }
        
        for(auto x: mp) {
            res.push_back(x.second);
        }
        
        return res;
    }
};