void findTopoSort(int node, int vis[], stack<int> &st, vector<pair<int,int>> adj[]){
	vis[node] = 1;
	for(auto nbr : adj[node]){
		if(!vis[nbr.first]){
			findTopoSort(nbr.first, vis, st, adj);
		}
	}
	st.push(node);
}

void shortestPath(int src, int n, vector<pair<int,int>> adj[]){
	int vis[n] = {0};
	stack<int> st;

	for(int i=0;i<n;i++){
		if(!vis[i]){
			findTopoSort(i, vis, st, adj);
		}
	}

	vector<int> dist(n,INT_MAX);
	dist[src] = 0;

	while(!st.empty()){
		int node = st.top();
		st.pop();

		if(dist[node] != INT_MAX){
			for(auto nbr : adj[node]){
				if(dist[node] + nbr.second < dist[nbr.first]){
					dist[nbr.first] = dist[node] + nbr.second;
				}
			}
		}
	}

	for(int i=0;i<n;i++){
		(dist[i] == 1e9) ? cout << "INF" : cout << dist[i] <<" ";
	}
}
