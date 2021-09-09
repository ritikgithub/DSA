//Program to return list containing vertices in Topological order. 

#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	
	
	void sort(vector<int>adj[],int indegree[],  vector<int>&ans, int V) {
	    
	    queue<int>q;
	   // int visitedNodes=0;
	    for(int i=0;i<V;i++) {
	      
	        if(indegree[i]==0) {
	            q.push(i);
	        }
	    }
	    while(!q.empty()) {
	        int node = q.front();
	        ans.push_back(node);
	        q.pop();
	       // visitedNodes++;
	        for(auto child: adj[node]) {
	            indegree[child]--;
	            if(indegree[child]==0)
	                q.push(child);
	        }
	    }
	   // if(visitedNodes<V) {
	   //     cout<<"Topological sort does not exist ...It have a cycle"<<endl;
	   // }
	}

	void calculateIndegree(vector<int>adj[],int V, int indegree[]) {
	    for(int i=0;i<V;i++) {
	        for(auto child: adj[i]) {
	            indegree[child]++;
	        }
	    }
	}
	

	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        int indegree[V];
        memset(indegree,0,sizeof(indegree));
        calculateIndegree(adj,V,indegree);
        vector<int> ans;
        sort(adj, indegree, ans, V);
        return ans;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends