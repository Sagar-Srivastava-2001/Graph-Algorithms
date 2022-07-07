#include<bits/stdc++.h>
vector<int> BFS(int V, vector<pair<int, int>> edges)
{
    vector<int> adj[V+1];
    
    for(auto x : edges){
        int u = x.first;
        int v = x.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=0;i<V;i++){
        sort(adj[i].begin(),adj[i].end());
    }
    
    vector<int> bfs;
    vector<bool> visited(V+1,false);
    queue<int> q;
    
    for(int i=0;i<V;i++){
        if(!visited[i]){        
            q.push(i);
            visited[i] = true;
            
            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                
                for(auto x : adj[node]){
                    if(!visited[x]){
                        q.push(x);
                        visited[x] = true;
                    }
                }
            }
        }
    }
    return bfs;
}
