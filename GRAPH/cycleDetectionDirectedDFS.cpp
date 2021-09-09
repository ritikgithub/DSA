//Program to detect cycle in directed graph using DFS

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
	
	bool iscycle(int s,vector<int>adj[], bool visited[], bool dfsVisited[]) {
	   visited[s] = true;
	   dfsVisited[s] = true;
	    for(auto child : adj[s]) {
	       if(dfsVisited[child])
	        return true;
	        else if(!visited[child])
	           if(iscycle(child,adj,visited,dfsVisited))
	                return true;
	    }
	    dfsVisited[s]=false;
	    return false;
	}
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	bool visited[V]={false};
	   	bool dfsVisited[V]={false};
	   	for(int i=0;i<V;i++) {
	   	    if(!visited[i]) {
	   	        if(iscycle(i,adj,visited,dfsVisited))
	   	            return true;
	   	    }
	   	}
	   	return false;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends