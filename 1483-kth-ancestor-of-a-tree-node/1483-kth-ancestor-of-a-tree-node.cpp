class TreeAncestor {
        // BINARY LIFTING TECHNIQUE
        // PRE-PROCESSING TIME : O(N * log N) 
        // TC FOR EACH QUERY : O(log N)
        // SC : O(N * log N)
        // N -> NO. OF NODES
        
        vector<vector<int>> up;
        vector<int>depth;
        int log;
public:
    TreeAncestor(int n, vector<int>& parent) {
        
            log = 0;
            
            while((1<<log) <= n) log++;
            
            up = vector<vector<int>>(n, vector<int>(log));
   
            for(int i=0; i<n; i++) up[i][0] = parent[i];
            for(int v=0; v<n; v++){
                    for(int j=1; j<log; j++){
                            if(up[v][j-1] == -1) up[v][j] = -1; 
                            else up[v][j] = up[up[v][j-1]][j-1];
                    }
            }
          
    }
    
    int getKthAncestor(int node, int k) {
        
         
            for(int j=0; j<log; j++){
                    if((k>>j) & 1) node = up[node][j];
                    if(node==-1) return -1; 
            }
            return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */