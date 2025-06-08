class Solution {
    // TC : O(N)
    // SC : O(1)
   
public:
    vector<int> lexicalOrder(int n) {
        vector<int>res;
        int cur_num = 1;
        for(int i=0;i<n;i++){
            res.push_back(cur_num);
            // proceeding into depth
            if(cur_num*10 <= n){
                cur_num*=10;
            }
            // going for sibling node
            else{
                while(cur_num % 10 == 9 || cur_num >= n ){
                    cur_num /= 10;
                }
                cur_num += 1;
            }
        }
        return res;
    }
};

//  ------------------ DFS(RECURSIVE) APPROACH ---------------
class Solution1 {
    // TC : O(N)
    // SC : O(log N)
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