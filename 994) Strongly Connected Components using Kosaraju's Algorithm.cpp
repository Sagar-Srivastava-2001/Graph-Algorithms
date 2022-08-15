#include<bits/stdc++.h>
/*
    Algorithm
    
    1) Sort all the nodes in order of their finishing time (Topo Sort)
    2) Transpose the Graph i.e Reverse all the edges
    3) Perform DFS according to the finishing time, i.e from topo sort ordering

    Time Complexity : O(N + E)
    Space Complexity : O(N + E) + O(N) + O(N)
*/

void dfs(int node,stack<int> & st, vector<int>adj[],vector<int>&vis){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,st,adj,vis);
        }
    }
    st.push(node);
}
void revdfs(int node, vector<int>transpose[],vector<int>&vis){
    vis[node]=true;
    for(auto it: transpose[node]){
        if(!vis[it]){
            revdfs(it,transpose,vis);
        }
    }
}

int stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<int> adj[n+1];
    
    for(auto x : edges){
        adj[x[0]].push_back(x[1]);
    }
    
    stack<int> s;
    vector<int> vis(n,0);
    
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,s,adj,vis);
        }
    }
    
    vector<int> transpose[n];
    
    for(int i=0;i<n;i++){
        vis[i] = 0;
        for(auto nbr : adj[i]){
            transpose[nbr].push_back(i);
        }
    }
    
    int count=0;
    while(!s.empty()){
        int top=s.top(); s.pop();
        if(!vis[top]){
            count++;
            revdfs(top,transpose,vis);
        }
    }
    return count;
}
