class Solution {
    unordered_map<string, vector<pair<string, double>>> adjList;
    unordered_map<string,bool> vis;
    double queryAns;
public:
    
    bool dfs(string startNode, string endNode, double runningProduct){
        
        if(startNode == endNode and adjList.find(startNode)!=adjList.end()) {
            queryAns = runningProduct;
            return true;
        }
        
        bool tempAns = false;
        vis[startNode] = true;
        
        for(int i = 0; i < adjList[startNode].size(); i++)
        {
            if(!vis[adjList[startNode][i].first])
            {
                tempAns = dfs(adjList[startNode][i].first, endNode,                                                               runningProduct*adjList[startNode][i].second);
                if(tempAns){
                    break;
                }
            }
        }
        
        vis[startNode] = false;
        
        return tempAns;
        
    }
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
     
        
        vector<double> ans(queries.size());
        //unordered_map<string, vector<pair<string, double>>> graph;
        
        for(int i=0; i<equations.size(); i++)
        {
            adjList[equations[i][0]].push_back({equations[i][1], values[i]});
            adjList[equations[i][1]].push_back({equations[i][0], (double) 1/values[i]});
            
            vis[equations[i][0]] = false;
            vis[equations[i][1]] = false;
        }
        
        for(int i=0; i<queries.size(); i++) {
            queryAns = 1;
            bool pathFound = dfs(queries[i][0], queries[i][1], 1);
            if(pathFound == true)
                ans[i] = queryAns;
            else 
                ans[i] = -1;
        }
        
        return ans;
    }
};