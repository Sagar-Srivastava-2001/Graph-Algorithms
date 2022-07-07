#include<bits/stdc++.h>
void dfs(int node, vector<bool> &vis, vector<int> adj[], vector<int> &component){
    component.push_back(node);
    vis[node] = true;
    
    for(auto nbr : adj[node]){
        if(vis[nbr] == false){
            dfs(nbr, vis, adj, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    vector<int> adj[V];
    
    for(int i=0;i<E;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> vis(V, false);
    
    for(int i=0;i<V;i++){
        if(vis[i] == false){
            vector<int> cmp;
            dfs(i,vis,adj,cmp);
            sort(cmp.begin(),cmp.end());
            ans.push_back(cmp);
        }
    }
    return ans;
}
