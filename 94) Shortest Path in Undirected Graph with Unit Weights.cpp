Question Link : https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0


#include<bits/stdc++.h>
vector<int> shortestPath( vector<pair<int,int>> edges , int V , int m, int s , int t){
    vector<int> adj[V+1];
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> distance(V+1,INT_MAX);
    
    vector<vector<int>> path(V+1);
    queue<int> q;
    
    distance[s] = 0;
    q.push(s);
    path[s].push_back(s);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto nbr : adj[node]){
            if(distance[nbr] > distance[node] + 1){
                distance[nbr] = distance[node] + 1;
                q.push(nbr);
                
                path[nbr] = path[node];
                path[nbr].push_back(nbr);
            }
        }
    }
    
    return path[t];
}
