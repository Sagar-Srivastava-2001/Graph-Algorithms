class Solution {
public:
    
    bool checkBipartite(int s, vector<vector<int>> &graph, vector<int> &visited){
        visited[s] = 1;
        queue<int> q;
        q.push(s);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto nbr : graph[node]){
                if(visited[nbr] == -1){
                    visited[nbr] = 1 - visited[node];
                    q.push(nbr);
                }
                else{
                    if(visited[nbr] == visited[node]){
                        return false;
                    }
                }
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
