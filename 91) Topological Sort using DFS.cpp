#include<bits/stdc++.h>

void topologicalSortDFS(int node, vector<int> adj[], vector<bool> &visited, stack<int> &s){
    visited[node] = true;
    
    for(auto nbr : adj[node]){
        if(!visited[nbr]){
            topologicalSortDFS(nbr, adj, visited, s);
        }
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int V, int E)  {
    stack<int> s;
    vector<int> topo;
    vector<int> adj[V];
    
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }
    
    vector<bool> visited(V,false);
    
    for(int i=0;i<V;i++){
        if(!visited[i]){
            topologicalSortDFS(i,adj,visited,s);
        }
    }
    
    while(s.size() > 0){
        int x = s.top();
        s.pop();
        topo.push_back(x);
    }
    return topo;
}
