class Solution {
public:
    
    bool checkBipartite(int node, vector<vector<int>> &graph, vector<int> &visited){
        if(visited[node] == -1)    visited[node] = 1;
        
        for(auto nbr : graph[node]){
            if(visited[nbr] == -1){
                visited[nbr] = 1 - visited[node];
                
                if(checkBipartite(nbr, graph, visited) == false){
                    return false;
                }
            }
            else if(visited[nbr] == visited[node]){
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,-1);
        
        for(int i=0;i<n;i++){
            if(visited[i] == -1){
                if(checkBipartite(i,graph,visited) == false)
                    return false;
            }
        }
        
        return true;
    }
};
