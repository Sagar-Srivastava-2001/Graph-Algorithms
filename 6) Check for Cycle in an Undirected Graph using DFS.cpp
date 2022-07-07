bool checkForCycle(int node, int parent, vector<bool> &visited, vector<int> adj[]){
    visited[node] = true;
    for(auto nbr : adj[node]){
        if(!visited[nbr]){
            if(checkForCycle(nbr, node, visited, adj))
                return true;
        }
        else{
            if(nbr != parent)
                return true;
        }
    }
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> adj[A+1];
    for(int i=0;i<B.size();i++){
        int u = B[i][0];
        int v = B[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> visited(A+1,false);
    
    for(int i=1;i<=A;i++){
        if(!visited[i]){
            if(checkForCycle(i,-1,visited,adj))
                return true;   
        }
    }
    return false;
}
