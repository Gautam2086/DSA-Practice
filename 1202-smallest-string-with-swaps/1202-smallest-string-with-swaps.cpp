class Solution {
public:
    vector<vector<int>> graph;
    // we will convert the given pair matrix in graph
    vector<bool> vis;
    // visited array to apply DFS
    
    void dfs(int i, vector<int>& indices, vector<char>& letters, string& s)
    {
        vis[i]= true;
        // mark the given node as vis
        indices.push_back(i);
        letters.push_back(s[i]);
        // push the index and char of index and letter
        
        for(auto u: graph[i])
        {
            if(!vis[u])
                dfs(u, indices, letters, s);
        // apply the dfs logic, i.e go to it neighbour and keep checking it recursively
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
    {
        int n= s.size();
        // there can be 'n' nodes possible in graph
        graph.resize(n);
        // resize our graph to n
        vis.resize(n, false);
        // initially all node in in graph would hold false as none of them is visited
        
        for(auto x: pairs) {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
            // traverse through complete pair matrix and convert it into graph
        }
        
        for(int i=0; i<n; i++) 
        {
            vector<int> indices;
            // to store original index of each char
            vector<char> letters;
            // to store each char parallel to it side in 'index' array
            
            if(!vis[i]) {
                dfs(i, indices, letters, s);
                // apply DFS to each connected part of graph , basically traverse through whole conncted                    component and
                // store it index and letters respectively
            }
            
            sort(indices.begin(), indices.end());
            sort(letters.begin(), letters.end());
            // sort both index and letters array
            // so that we get the minimum char at the earlier (As in case of lexicographical smaller )
            
            for(int i=0; i<indices.size(); i++)
            {
                s[indices[i]]= letters[i]; 
                // just traverse in letter array and concatanate the string
            }
        }
        
        return s;
        // return the ans string
    }
};