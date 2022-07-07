void adjacency_list_undirected_graph(){
    int n,m;
    cin>>n>>m;

    // Non Weights
    vector<int> adj[n+1];

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Weighted Graph
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
}
