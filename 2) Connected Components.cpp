void connected_components()
{
	vector<int> vis(n+1,0);	// Define it Globally
  int cnt = 0;
  
	for(int i=1;i<=n;i++){
		if(!vis[i]){
      cnt++;              // If want to find the number of connected componenets
			bfs()	||	dfs();    //  Perform BFS or DFS and Mark the neighbours as true
		}
	}
}
