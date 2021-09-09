//Program To find whether graph is bipartite or not using DFS

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

   bool isbipartite(int i, vector<int>adj[],int color[]) {
      for(auto child: adj[i]) {
          if(color[child]!=-1) {
              if(color[child] == color[i])
                return false;
          } 
          else {
              color[child] = !color[i];
              if(!isbipartite(child,adj,color))
                    return false;
          }
      }
      return true;
   }

	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    memset(color,-1,sizeof(color));

	    for(int i=0;i<V;i++) {
	        if(color[i]==-1) 
	        {
	            color[i]=0;
	            if(!isbipartite(i,adj,color))
	                return false;
	        }
	    }
	    return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends