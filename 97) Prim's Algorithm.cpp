// Brute Force : O(N^2)
void primsAlgo(){
 	int N, m;
 	cin>>N>>m;
 	vector<pair<int,int>> adj[N];

 	int a,b,wt;
 	for(int i=0;i<m;i++){
 		cin>>a>>b>>wt;
 		adj[a].push_back({b,wt});
 		adj[b].push_back({a,wt});
 	}

 	int parent[N];
 	int key[N];
 	bool mstSet[N];

 	for(int i=0;i<N;i++){
 		key[i] = INT_MAX, mstSet[i] = false, parent[i] = -1;
 	}

 	key[0] = 0;
 	parent[0] = -1;

 	for(int count = 0; count < N-1; count++){		// Iterate for N-1 Edges as in MST there will be N-1 edges
 		int Min = INT_MAX;
 		int node;

 		for(int v=0;v<N;v++){
 			if(!mstSet[v] and key[v] < Min){
 				Min = key[v], node = v;
 			}
 		}

 		mstSet[node] = true;

 		for(auto nbr : adj[node]){
 			int v = nbr.first;
 			int weight = it.second;

 			if(mstSet[v] == false and weight < key[v]){
 				parnet[v] = node, key[v] = weight;
 			}
 		}
 	}

 	for(int i=1;i<N;i++){
 		cout<<parent[i]<<" - "<<i<<"\n";
 	}
}

// Efficient Approach : O(NlogN)
void primsAlgo(){
	int N, m;
 	cin>>N>>m;
 	vector<pair<int,int>> adj[N];

 	int a,b,wt;
 	for(int i=0;i<m;i++){
 		cin>>a>>b>>wt;
 		adj[a].push_back({b,wt});
 		adj[b].push_back({a,wt});
 	}

 	int parent[N];
 	int key[N];
 	bool mstSet[N];

 	for(int i=0;i<N;i++){
 		key[i] = INT_MAX, mstSet[i] = false, parent[i] = -1;
 	}

 	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
 	key[0] = 0;
 	parent[0] = -1;
 	pq.push({0,0});		// {Key, Index}

 	for(int count = 0; count < N-1; count++){		// Iterate for N-1 Edges as in MST there will be N-1 edges
 		int Min = INT_MAX;
 		int node = pq.top().second; 
 		pq.pop();

 		mstSet[node] = true;

 		for(auto nbr : adj[node]){
 			int v = nbr.first;
 			int weight = it.second;

 			if(mstSet[v] == false and weight < key[v]){
 				parnet[v] = node, key[v] = weight;
 				pq.push({key[v], v});
 			}
 		}
 	}

 	for(int i=1;i<N;i++){
 		cout<<parent[i]<<" - "<<i<<"\n";
 	}
}
