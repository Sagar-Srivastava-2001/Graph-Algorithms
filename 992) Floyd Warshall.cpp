int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<vector<int>> dis(n+1,vector<int>(n+1,1e9));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)
                dis[i][j] = 0;
        }
    }
    
    for(auto x : edges){
        int u = x[0];
        int v = x[1];
        int wt = x[2];
  
        dis[u][v] = wt;
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if((dis[i][k] != 1e9 and dis[k][j] != 1e9)){
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }
    
    return dis[src][dest];
}
