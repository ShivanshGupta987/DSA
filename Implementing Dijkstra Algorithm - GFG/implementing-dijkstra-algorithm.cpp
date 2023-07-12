//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class mycomp{
    public:
        bool operator()(const vector<int>& a, const vector<int>& b){
            return a[0] > b[0];
        }
};

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int source)
    {
        // Code here
        vector<int>dist(n,1e9);
        dist[source] = 0;
        priority_queue<vector<int>,vector<vector<int>>,mycomp>pq;
        pq.push({0,source});
        
        while(!pq.empty()){
            int d = pq.top()[0], u = pq.top()[1];
            pq.pop();
            if(d!=dist[u])continue;
            for(auto & edge : adj[u]){
                int v = edge[0], wt = edge[1];
                if(dist[v] > dist[u] + wt ){
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v],v});
                }
            }
        }
        
        return dist;

    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends