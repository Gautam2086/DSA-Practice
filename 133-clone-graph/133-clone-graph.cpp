/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    void edges(unordered_map<Node*, Node*>& mp) {       // make edges in new cloned nodes
        
        for(auto u : mp) {
            for(auto v : u.first->neighbors) {
                u.second->neighbors.push_back(mp[v]);
            }
        }
    }
    
    void dfs(Node* curr, set<Node*>& vis, unordered_map<Node*, Node*>& mp)
    {
        Node* clone= new Node(curr->val);
        vis.insert(curr);
        mp[curr]= clone;
        
        for(auto v: curr->neighbors)
        {
            if(vis.find(v) == vis.end())            // visited set
                dfs(v, vis, mp);
        }
    }
    
    Node* cloneGraph(Node* node) {
        
        if(node == NULL)
            return NULL;
        
        if(node->neighbors.size() == 0) {            //if only one node present no neighbor
            Node* clone= new Node(node->val);   
            return clone;
        }
        
        unordered_map<Node*, Node*> mp;
        set<Node*> vis;
        
        dfs(node, vis, mp);
        edges(mp);
        
        return mp[node];
    }
};