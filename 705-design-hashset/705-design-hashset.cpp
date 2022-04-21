/*
    Time Complexity: O(N/BucketSize)
    Space Complexity: O(N)
*/
class MyHashSet {
public:
    int bucketSize= 123;
    vector<int> bucket[123];
    
    MyHashSet() {
    }
    
    void add(int key) {
        int idx= key % bucketSize;
        if(!contains(key)) {
            bucket[idx].push_back(key);
        }
    }
    
    void remove(int key) {
        int idx= key % bucketSize;
        
        for(int i=0; i<bucket[idx].size(); i++)
        {
            if(bucket[idx][i] == key)
            {
                bucket[idx].erase(bucket[idx].begin() + i);
                break;
            }   
        }
    }
    
    bool contains(int key) {
        int idx= key % bucketSize;
        
        for(auto itr: bucket[idx]) {
            if(itr == key)
                return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */