class Solution {
const int INF = 1e9;
        // TC : O(E log V)
        // SC : O(V + E)
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
            vector<pair<int,int>> adj[n];
            // vector<bool>visited(n,false);
            for(auto edge:times){
                    adj[edge[0]-1].push_back({edge[1]-1,edge[2]});
            }
            
            set<pair<int,int>>st;
            st.insert({0,k-1});
            
            vector<int>dist(n,INF);
            dist[k-1]=0;
            while(!st.empty()){
                    auto node = *st.begin();
                    int v = node.second;
                    int dist_v = node.first;
                    st.erase(st.begin());
                    // if(visited[v])continue;
                    // visited[v]=true;
                    
                    for(auto child:adj[v]){
                            int child_v = child.first;
                            int wt = child.second;
                            if(dist[v]+wt<dist[child_v]){
                                    dist[child_v] = dist[v]+wt;
                                    st.insert({dist[child_v],child_v});
                            }
                    }
                    
            }
            
            int mx = 0;
            
            for(int i=0;i<dist.size();i++){
                    // cout<<dist[i]<<" ";
                    mx = max(mx,dist[i]);
            }
            return mx==INF?-1:mx;
            
            
            
            
    }
};