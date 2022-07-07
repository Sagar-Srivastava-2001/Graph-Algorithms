
bool checkForCycle(int s, int A, vector<int> adj[], vector<bool> &visited){
    queue<pair<int,int>> q;     // {Node, Parent}
    q.push({s,-1});
    visited[s] = true;
    
    while(!q.empty()){
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        
        for(auto nbr : adj[node]){
            if(!visited[nbr]){
                visited[nbr] = true;
                q.push({nbr,node});
            }
            else if(nbr != par){
                return true;
            }
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
    
    vector<bool> vis(A+1,false);
    
    for(int i=1;i<=A;i++){
        if(!vis[i]){
            if(checkForCycle(i,A,adj,vis) == true)
                return true;
        }
    }
    return false;
}
