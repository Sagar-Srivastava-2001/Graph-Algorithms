#include<bits/stdc++.h>
using ppi = pair<int,int>;    //  {dist, node}
vector<int> dijkstra(vector<vector<int>> &vec, int V, int E, int src) {
    priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
    vector<pair<int,int>> adj[V];
    
    for(auto x : vec){
        int u, v, wt;
        u = x[0];    v = x[1];    wt = x[2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    
    vector<int> distance(V,INT_MAX);
    distance[src] = 0;
    pq.push({0,src});
    
    while(!pq.empty()){
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(auto nbr : adj[node]){
            int next = nbr.first;
            int nextDist = nbr.second;
            
            if(distance[next] > distance[node] + nextDist){
                distance[next] = distance[node] + nextDist;
                pq.push({distance[next], next});
            }
        }
    }
    return distance;
}
