#include<bits/stdc++.h>

bool checkForCycleDFS(int s, vector<int> adj[], vector<bool> &visited, vector<bool> &dfs_visited){
    visited[s] = true;
    dfs_visited[s] = true;
    
    for(auto nbr : adj[s]){
        if(!visited[nbr]){
            if(checkForCycleDFS(nbr, adj, visited, dfs_visited))
                return true;
        }
        else{
            if(visited[nbr] == true and dfs_visited[nbr] == true){
                return true;
            }
        }
    }
    dfs_visited[s] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector <pair<int,int>> & edges) {
    vector<int> adj[n+1];
    vector<bool> visited(n+1,false);
    vector<bool> dfs_visited(n+1,false);
    
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
    }
    
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(checkForCycleDFS(i,adj,visited,dfs_visited))
                return true;
        }
    }
    return false;
}
