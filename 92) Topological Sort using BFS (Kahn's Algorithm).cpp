#include<bits/stdc++.h>

vector<int> topoSortBFS(int V, vector<int> adj[]){
    queue<int> q;
    vector<int> indegree(V,0);
    
    for(int i=0;i<V;i++){
        for(auto nbr : adj[i]){
            indegree[nbr]++;
        }
    }
    
    for(int i=0;i<V;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        
        for(auto nbr : adj[node]){
            indegree[nbr]--;
            
            if(indegree[nbr] == 0)
                q.push(nbr);
        }
    }
    
    return topo;
}

vector<int> topologicalSort(vector<vector<int>> &edges, int V, int E)  {
    vector<int> adj[V];
    
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }
    
   return topoSortBFS(V,adj);
}
