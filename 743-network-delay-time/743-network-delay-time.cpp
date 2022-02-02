/*
Goal:
Find the time taken by the signal to cover all the nodes.    
                    OR
Find the minimum time to reach the farthest node. (provided all nodes can be visited from node k)
If any node is no reachable from k (source), then return -1

Approach: 
Dijkstra's Algo: Given a weighted, undirected and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto x: times)
            adj[x[0]].push_back({x[1], x[2]});
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // {dis, from the node}
        
        vector<int> dist(n+1, INT_MAX);
        dist[k]= 0;
        
        pq.push({0, k});                                    // {dis, from the node}
        
        while(!pq.empty())
        {
            int dis= pq.top().first;
            int prev= pq.top().second;
            pq.pop();
            
            for(auto it: adj[prev]) 
            {
                int nextNode= it.first;
                int nextDis= it.second;
                
                if(dist[nextNode] > dis + nextDis) {
                    dist[nextNode]= dis + nextDis;
                    pq.push({dis+nextDis, nextNode});        // {dis, from the node}
                }
            }
        }
        
        long long ans= *max_element(dist.begin()+1, dist.end());
        
        return ans==INT_MAX ? -1 : ans;
    }
};