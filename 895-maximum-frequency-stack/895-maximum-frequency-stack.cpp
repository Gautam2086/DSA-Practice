class FreqStack {
public:
    priority_queue<pair<int, pair<int, int>>> pq;   // freq, pos, value
    unordered_map<int, int> freq;                   // for finding frequency
    int pos= 0;
    
    FreqStack() {
    }
    
    void push(int val) {
        freq[val]++;
        pos++;
        pq.push({freq[val], {pos, val} });
    }
    
    int pop() {
        auto curr= pq.top(); pq.pop();
        freq[curr.second.second]--;
        return curr.second.second;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */