class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;      // min heap
    int s;
    KthLargest(int k, vector<int>& nums) {
        s= k;
        for(auto n: nums) {
            pq.push(n);
            if(pq.size() > k)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>s){
            pq.pop();
        } 
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */