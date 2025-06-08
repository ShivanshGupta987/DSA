class Solution {
    void solve(vector<int>& res, int num, int maxx){
        for(int i=0;i<10;i++){
            int new_num = num*10 + i;
            if(new_num > maxx) return;
            res.push_back(new_num);
            solve(res, new_num, maxx);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int>res;
        for(int i=1;i<min(10,n+1);i++){
            res.push_back(i);
            solve(res, i, n);
        }
        return res;
    }
};