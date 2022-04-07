class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;
        int n= stones.size();
        
        for(int i=0; i<n; i++) {
            pq.push(stones[i]);
        }
        
        while(n>1) 
        {
            int first= pq.top();    pq.pop();
            int second= pq.top();   pq.pop();
            n-= 2;
            
            if(first - second > 0) {
                pq.push(first - second);
                n++;
            }
        }
        if(!pq.empty())
            return pq.top();
        else
            return 0;
    }
};