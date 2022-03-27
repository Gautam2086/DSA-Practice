class Solution {
public:
    int binary(vector<int> v) {         //no. of soldier using binary search on curr row
        int lo= 0;
        int hi= v.size()-1;
        
        while(lo<=hi)
        {   
            int mid= lo+(hi-lo) /2 ;
            
            if(v[mid] == 0)
                hi= mid-1;
            else
                lo= mid+1;    
        }
        return lo;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
                                                        // min heap => {soldiers , ith row}
        
        for(int i=0; i<mat.size(); i++) {
            int ones= binary(mat[i]);
            pq.push({ones, i});
        }
        
        vector<int> ans;
        
        for(int i=0; i<k; i++) {
            pair<int, int> p= pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        return ans;
    }
};