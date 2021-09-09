//Program to detect cycle in directed graph using BFS

#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    
	bool iscycle(vector<int>adj[],int indegree[], int V) {
	    
	    queue<int>q;
	    int visitedNodes=0;
	    for(int i=0;i<V;i++) {
	      
	        if(indegree[i]==0) {
	            q.push(i);
	        }
	    }
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop();
	        visitedNodes++;
	        for(auto child: adj[node]) {
	            indegree[child]--;
	            if(indegree[child]==0)
	                q.push(child);
	        }
	    }
	    if(visitedNodes!=V) {
	      return true;
	    }
	    else    
	        return false;
	}
	
	void calculateIndegree(vector<int>adj[],int V, int indegree[]) {
	    for(int i=0;i<V;i++) {
	        for(auto child: adj[i]) {
	            indegree[child]++;
	        }
	    }
	}
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    int indegree[V];
        memset(indegree,0,sizeof(indegree));
        calculateIndegree(adj,V,indegree);
        if(iscycle(adj, indegree, V))
            return true;
        else
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