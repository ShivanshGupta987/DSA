class DSU{
    vector<int>par;
public: 
    DSU(){
        par.resize(26);
        for(int i=0;i<26;i++){
            par[i] = i;
        }
    }
    int find_par(int v){
        if(v==par[v]) return v;
        return par[v] = find_par(par[v]);
    }

    void do_union(int u, int v){
        u = find_par(u);
        v = find_par(v);
        if(u==v) return;
        if(u>v) swap(u,v);
        par[v] = u;
    }

};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size(), m = baseStr.size();
        DSU dsu;
        for(int i=0;i<n;i++){
            dsu.do_union(s1[i]-'a', s2[i]-'a');
        }
        string res(m,' ');
        for(int i=0;i<m;i++){
            res[i] = 'a' + dsu.find_par(baseStr[i]-'a');
        }
        return res;
    }
};