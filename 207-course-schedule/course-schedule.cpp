class Solution {
    // TC : O(V+E) OR O(N)
    // SC : O(V+E) OR O(N)
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int>indeg(n);
        vector<vector<int>>adj(n);

        for(auto & edge : prerequisites){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            indeg[v]++;
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)q.push(i);
        }
        int cnt = 0;

        while(!q.empty()){
            cnt++;
            int u = q.front();
            q.pop();
            for(auto & v : adj[u]){
                if(--indeg[v]==0) q.push(v);
            }
        }
        return cnt==n;
    }
};