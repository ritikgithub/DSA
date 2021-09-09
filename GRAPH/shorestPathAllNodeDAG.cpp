//Program to find shortest distance to all node from source in DAG

#include <bits/stdc++.h>
using namespace std;

void toposort(int i, vector<pair<int,int>> adj[], vector<bool>& visited, stack<int>& topoSort) {
    visited[i]=true;
    for(auto j: adj[i]) {
        int child = j.first;
        if(!visited[child]) {
            toposort(child,adj,visited,topoSort);
        }
    }
    topoSort.push(i);
}

vector<int> dfsModified(int s, vector<pair<int,int>> adj[], int V) {
    vector<int> dist(V,INT_MAX);
    vector<bool> visited(V,false);
    stack<int> topoSort;
    toposort(s, adj, visited, topoSort);
    dist[s] = 0;
    int child,weight;
    while(!topoSort.empty()) {
        int node = topoSort.top();
        topoSort.pop();
        for(auto i: adj[node]) {
            child = i.first;
            weight = i.second;
            if(dist[node]+weight<dist[child])
                dist[child] = dist[node]+weight;
        }
    }
    
   return dist;
    
}


int main() {
	   int V,E,u,v,s,w;
    cin>>V>>E>>s;
    vector<pair<int,int>> adj[V];
    for(int i=0;i<E;i++) {
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
 
    vector<int> dist = dfsModified(s,adj,V);
    for(int i=0;i<V;i++)
        cout<<dist[i]<<" ";
	return 0;

}