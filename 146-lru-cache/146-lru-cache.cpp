/*
DLL: Doubly Linked List

        |Node1|  ---->|Node2|  ---->|Node3|
        |Node1|  <----|Node2|  <----|Node3|

        Each node has two pointers: next as well as previous
*/

class LRUCache {
public:
    class node{                                 // Class for Doubly linked list
    public:
        int key;
        int val;
        node* next;
        node* prev;
        
        node(int _key, int _val) {              // Constructor
            key= _key;
            val= _val;
        }           
    };
    
    node* head= new node(-1, -1);
    node* tail= new node(-1, -1);
    
    int cap;                                    // Capacity
    unordered_map<int, node*> mp;               // [val, address]
    
    LRUCache(int capacity) {
        cap= capacity;
        head->next= tail;
        tail->prev= head;
    }
    
    void addNode(node* newNode) {
    
        node* tmp= head->next;
        newNode->next= tmp;
        newNode->prev= head;
        head->next= newNode;
        tmp->prev= newNode;
    }
    
    void deleteNode(node* delNode) {
        node* delPrev= delNode->prev;
        node* delNext= delNode->next;
        delPrev->next= delNext;
        delNext->prev= delPrev;
    }
    
    int get(int key_) {                         // O(1)
        if(mp.find(key_) != mp.end()) {
            node* resNode= mp[key_];            // get val stored previously
            int res= resNode->val;  
            
            mp.erase(key_);                     // Erase from map
            deleteNode(resNode);                // delete from DLL
                
            addNode(resNode);                   // Insert in DLL right after head
            mp[key_]= head->next;               // reassign in map with [key, new address]
                                                // and make it is last recently used guy
            return res;
        }
        return -1;                              // if key is not found in map
    }
    
    void put(int key_, int value) {             // O(1)
        if(mp.find(key_) != mp.end()) {
            node* existingNode= mp[key_];
            mp.erase(key_);
            deleteNode(existingNode);
        }
        if(mp.size() == cap) {
            mp.erase(tail->prev->key);          // delete least recently used guy 
            deleteNode(tail->prev);
        }
        
        addNode(new node(key_, value));         // Insert in DLL right after head
        mp[key_]= head->next;                   // and make it is last recently used guy
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */