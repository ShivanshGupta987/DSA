class Solution {
    vector<vector<int>>res;
        void bt(vector<int>& a, int target,int ind,vector<int>& temp){
        
                if(target==0){
                        res.push_back(temp);
                        return;
                }
                for(int i=ind;i<a.size();i++){
                        
                        if(target-a[i]<0)break;
                        temp.push_back(a[i]);
                        bt(a,target-a[i],i,temp);  
                        temp.pop_back();
                }
        }
public:
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
           sort(a.begin(),a.end());
            vector<int>temp;
            bt(a,target,0,temp);
            
            return res;
    }
};