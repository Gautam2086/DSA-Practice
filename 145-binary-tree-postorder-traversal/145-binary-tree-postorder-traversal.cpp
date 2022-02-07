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

/* Algo: iterative way to get preorder traversal of binary tree

Steps : 
1. initial config : Take the root and put it in the 1st stack.
2. Now, take the top from the 1st stack and put it into the 2nd stack
3. After that, if the top in 2nd stack has left → add it in 1st stack.  And if the top in 2nd stack has right → add it in the 1st stack.
4. Now again, take the top from the 1st stack and put it into the 2nd stack. Repeat step 2 & 3 untill 1st stack is empty.
5. Pop the element from the 2nd stack and print.

*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> postorder;
        if(root == NULL)    return postorder;
        stack<TreeNode*> s1, s2;
        
        s1.push(root);
        
        while(!s1.empty())
        {
            root= s1.top(); s1.pop();
            
            s2.push(root);
            if(root->left != NULL)
                s1.push(root->left);
            
            if(root->right != NULL)
                s1.push(root->right);
        }
        
        while(!s2.empty()) 
        {
            postorder.push_back(s2.top()->val);
            s2.pop();
        }
        return postorder;
    }
};