#include<bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int N, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<int,int>> adj[N+1];
    for(int i=0;i<g.size();i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    vector<int> key(N+1, INT_MAX);
    vector<bool> mst(N+1, false);
    vector<int> parent(N+1,-1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    
    key[1] = 0;
    parent[1] = -1;
    
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        mst[node] = true;
        
        for(auto nbr : adj[node]){
            int v = nbr.first;
            int weight = nbr.second;
            
            if(mst[v] == false and weight < key[v]){
                parent[v] = node;
                key[v] = weight;
                pq.push({key[v],v});
            }
        }
    }
    
    vector<pair<pair<int,int>,int>> ans;
    
    for(int i=2;i<=N;i++){
        ans.push_back({{parent[i],i},key[i]});
    }
    return ans;
}
