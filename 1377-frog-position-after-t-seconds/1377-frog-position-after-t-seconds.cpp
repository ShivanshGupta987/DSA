class Solution {
        // TC : O(N)
        // SC : O(H)
        // H -> HEIGHT OF THE TREE
        
vector<vector<int>> adj;
vector<bool>seen;
int target;
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
          
            if(n==1) return 1.0;
            this->target = target;
            
            adj = vector<vector<int>>(n+1,vector<int>());
            seen = vector<bool>(n+1,false);
            
            for(auto e:edges)
            {
                    adj[e[0]].push_back(e[1]);
                    adj[e[1]].push_back(e[0]);
            }
            return dfs(1,t);
            
            
    }
  private:
        double dfs(int i, int t)
        {
                if(i!=1 && adj[i].size()==1 || t==0)
                        return i==target;
                
                seen[i]=true;
                
                double sum = 0.0;
                for(auto child : adj[i])
                {
                        if(!seen[child])
                        {
                           sum += dfs(child,t-1);          
                        }
                }
                
                return sum/(adj[i].size()- (i!=1));
        }
       
};