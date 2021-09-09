#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:

    void bfs(int s, vector<int> adj[], bool visited[], vector<int>&ans) {
        queue<int> q;
        q.push(s);
        visited[s] = true;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto i: adj[node]) {
                if(!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    bool visited[V];
	    memset(visited,false, sizeof(visited));
	    vector<int> ans;
	   for(int i=0;i<V;i++) {
	       if(!visited[i])
	            bfs(0,adj,visited,ans);
	   }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends