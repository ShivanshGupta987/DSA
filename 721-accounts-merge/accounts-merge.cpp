class DSU{
    int n;
    vector<int>par;
    vector<int>sz;
    public:
    DSU(int n){
        this->n = n;
        this->par.resize(n);
        this->sz.resize(n);
        for(int i=0;i<n;i++){
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find_set(int u){
        if(par[u]==u) return u;
        return par[u] = find_set(par[u]);
    }

    void do_union(int u, int v){
        u = find_set(u);
        v = find_set(v);
        if(u==v) return;

        if(sz[v]<sz[u]){
            swap(u,v);
        }
        par[u] = v;
        sz[v] += sz[u];
    }

};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        unordered_map<string,int>mp;
        int n = accounts.size();
        DSU dsu(n);
        for(int i=0;i<n;i++){
            string name = accounts[i][0];
            int m = accounts[i].size();
            for(int j=1;j<m;j++){
                if(mp.find(accounts[i][j])!=mp.end()){
                    dsu.do_union(i, mp[accounts[i][j]]);
                }
                else mp[accounts[i][j]] = i;
            }
        }

        unordered_map<int,set<string>>unique_users;

        for(int i=0;i<n;i++){
            string name = accounts[i][0];
            int m = accounts[i].size();
            for(int j=1;j<m;j++){
                unique_users[dsu.find_set(i)].insert(accounts[i][j]);
            }
        }

        vector<vector<string>>res;
        for(auto &[key, emails] : unique_users){
            vector<string>temp;
            temp.push_back(accounts[key][0]);
            temp.insert(temp.end(), emails.begin(), emails.end());
            res.push_back(temp);
        }
        return res;
    }
};