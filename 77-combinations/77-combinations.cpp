class Solution {

        vector<vector<int>>res;
public:
    vector<vector<int>> combine(int n, int k) {
            vector<int>tem;
        rec(k,n,tem,1);
            return res;
    }
        private : 
        void rec(int k,int n,vector<int>&temp,int ind){
                if(k==0){res.push_back(temp);return;}
                
                for(int i=ind;i<=n;i++){
                        temp.push_back(i);
                        rec(k-1,n,temp,i+1);
                        temp.pop_back();
                }
        }
};