/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
/* Approach: Using Hashmap (Extra Space)

1. Create Hashmap {key: Original node, Val: Copied node}
2. Add link of next and random pointer ie:
    2.1 Point each copied nodes NEXT to original nodes NEXT
    2.2 Point each copied nodes RANDOM to original nodes RANDOM    
3. Return map[head]

=> Time: O(N)
=> Space: O(N)
*/
      
    Node* copyRandomList(Node* head) {
        
        unordered_map<Node*, Node*> mp;
        
        Node* tmp= head;                        // Temporary node for iterating list
        
        while(tmp) {
            mp[tmp]= new Node(tmp->val);
            tmp= tmp->next;
        }
            
        tmp= head;
        
        while(tmp) 
        {
            mp[tmp]->next= mp[tmp->next];
            mp[tmp]->random= mp[tmp->random];
            
            tmp= tmp->next;
        }
        
        return mp[head];
    }
};