class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
                                                        // min heap => {soldiers , ith row}
        
        for(int i=0; i<mat.size(); i++)
        {
            int ones= 0;
            for(int j=0; j<mat[0].size(); j++) {
                if(mat[i][j] == 1)
                    ones++;
            }
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