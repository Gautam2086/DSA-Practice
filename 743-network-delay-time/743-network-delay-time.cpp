class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector< pair<int,int> > adj[n+1];
        
        for(auto x: times) {
            adj[x[0]].push_back({x[1], x[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // {dis, from the node}
        
        vector<int> dist(n+1, INT_MAX);
        
        dist[k] = 0;
        pq.push({0, k});
        
        while(!pq.empty())
        {
            int dis= pq.top().first;
            int node= pq.top().second;
            pq.pop();
            
            for(auto it: adj[node])
            {
                int nextNode= it.first;
                int nextDis= it.second;
                
                if(dist[nextNode] > dis + nextDis) {
                    dist[nextNode] = dis + nextDis;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }
        
        int ans= *max_element(dist.begin()+1, dist.end());      // as question is 1-indexed
        
        return ans==INT_MAX ? -1 : ans;
    }
};