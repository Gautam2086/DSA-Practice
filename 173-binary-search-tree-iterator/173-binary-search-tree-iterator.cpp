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
class BSTIterator {
public:
    vector<int> v;
    int i= 0;
    
    void inorder(TreeNode* head) {
        if(!head)   return;
        inorder(head->left);
        v.push_back(head->val);
        inorder(head->right);
    }
    
    BSTIterator(TreeNode* root) { 
        inorder(root);
    }
    
    int next() {
        int ans= v[i++];
        return ans;
    }
    
    bool hasNext() {
        if(i<v.size())
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */