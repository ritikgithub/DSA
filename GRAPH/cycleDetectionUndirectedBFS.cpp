//To detect cycle in undirected graph using BFS


#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    
    bool iscycle(int i, vector<int>adj[], bool visited[]) {
      queue<pair<int,int>> q;
      visited[i]=true;
      q.push({i,-1});
      while(!q.empty()) {
          int node = q.front().first;
           int parent = q.front().second;
          q.pop();
          for(auto child : adj[node]) {
              if(child!=parent) {
                  if(visited[child])
                    return true;
                    else {
                         visited[child]=true;
                        q.push({child,node});
                    }
                  }
             
          }
         
      }
       return false;
    }
    
	bool isCycle(int V, vector<int>adj[])
	{
	    bool visited[V]={false};
	    for(int i=0;i<V;i++) {
	        if(!visited[i]) {
	            if(iscycle(i,adj,visited))
	                return true;
	        }
	    }
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends