#include<bits/stdc++.h>

bool isCycle(int V, vector<int> adj[]){
    queue<int> q;
    vector<int> indegree(V+1,0);
    
    for(int i=1;i<=V;i++){
        for(auto nbr : adj[i]){
            indegree[nbr]++;
        }
    }
    
    for(int i=1;i<=V;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    
    vector<int> topo;
    int cnt = 0;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;
        
        for(auto nbr : adj[node]){
            indegree[nbr]--;
            
            if(indegree[nbr] == 0){
                q.push(nbr);
            }
        }
    }
    
    return cnt == V ? false : true;
}

int detectCycleInDirectedGraph(int V, vector <pair<int,int>> & edges) {
    vector<int> adj[V+1];
    
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
    }
    
    return isCycle(V,adj);
}
