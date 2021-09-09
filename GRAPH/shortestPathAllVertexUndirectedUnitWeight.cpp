//Program To find shortest path from source to all vertex in a graph having unit edges.

#include <bits/stdc++.h>
using namespace std;

vector<int> bfsModified(int s, vector<int>adj[], int V) {
    vector<int> dist(V,INT_MAX);
    queue<int> q;
    dist[s]=0;
    q.push(s);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto child: adj[node]) {
            if(dist[node]+1<dist[child]) {
                dist[child] = dist[node]+1;
                q.push(child);
            }
        }
    }
    return dist;
}

int main() {
    int V,E,u,v,s;
    cin>>V>>E>>s;
    vector<int> adj[V];
    for(int i=0;i<E;i++) {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    vector<int> dist = bfsModified(s,adj,V);
    for(int i=0;i<V;i++)
        cout<<dist[i]<<" ";
	return 0;
}
