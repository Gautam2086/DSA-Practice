/*
- Make a freq array
- inc freq of a key to 1 if add func is called
- dec freq of a key to 2 if remove func is called
- when contain func is called, return T if freq==1 else return F
*/
class MyHashSet {
public:

    vector<int> freq;
    MyHashSet() {
        freq.resize(1000001, 0);
    }
    
    void add(int key) {
        freq[key]= 1;
    }
    
    void remove(int key) {
        freq[key]= 0;
    }
    
    bool contains(int key) {
        return freq[key]==1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */