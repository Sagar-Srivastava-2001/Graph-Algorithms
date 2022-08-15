int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dist(n+1,1e9);
    dist[src] = 0;
    
    for(int times = 1; times <= n-1; times++){
        for(auto x : edges){
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            
            if(dist[u] != 1e9 and (dist[u] + wt < dist[v])){
                dist[v] = wt + dist[u];
            }
        }
    }
    
    bool negative = false;
    
    for(auto x : edges){
        int u = x[0];
        int v = x[1];
        int wt = x[2]; 
        
        // While iterating over the edges one more time, if there is any relaxation possible again, then it means there is a negative cycle in the graph
        if(dist[u] != 1e9 and (dist[u] + wt < dist[v])){
            negative = true;
            break;
        }
    }
    
    if(negative == true)    return 1e9;
    
    return dist[dest];
}
