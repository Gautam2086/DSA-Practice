/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)   return root;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int s= q.size();
            
            Node* prev= NULL;
            while(s--)
            {
                Node* tmp= q.front();   q.pop();
                
                tmp->next= prev;
                prev= tmp;
                
                if(tmp->right)             // first insert right ptr
                    q.push(tmp->right);
                if(tmp->left)              // then insert left ptr
                    q.push(tmp->left);
            }
        }
        return root;
    }
};