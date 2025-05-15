class UnionFind{
    vector<int>par, rank;
public:
    UnionFind(int n){
        par.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            par[i] = i;
        }
    }
    int find(int u){
        if(par[u] == u) return u;
        return par[u] = find(par[u]);
    }

    void do_union(int u, int v){
        u = find(u);
        v = find(v);
        if(u==v) return;
        if(rank[u] < rank[v]) swap(u, v);
        par[v] = u;
        if(rank[u]==rank[v]) rank[u]++;
    }
};
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>parent(n+1, 0), candA, candB;

        // Step 1 : Checking whether there is a node with two parents
        for(auto & edge : edges){
            int u = edge[0], v = edge[1];
            if(parent[v] == 0){
                parent[v] = u;
            }
            else{
               candA = {parent[v], v};
               candB = edge;
               edge[1] = -1; //setting the edge invalid
            }
        }
        if(candA.empty())assert(candA.empty()==true && candB.empty()==true);
        // Step 2 : union find 

        UnionFind uf(n+1);
        for(auto & edge : edges){
            int u = edge[0], v = edge[1];
            if(v==-1) continue;
            // cout<<"("<<u<<","<<v<<")  ";
            u = uf.find(u);
            v = uf.find(v);
            // cout<<"("<<u<<","<<v<<")\n";
            if(u!=v) uf.do_union(u,v);
            else{
                if(candA.empty()) return edge;
                else return candA;
            }
        }
        return candB;
    }
};      