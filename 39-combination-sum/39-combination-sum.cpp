class Solution {
        vector<vector<int>>res;
        void bt(int ind,vector<int>&arr, int target,vector<int>&temp){
                if(target==0){
                        res.push_back(temp);return;
                }
                for(int i=ind; i<arr.size();i++){
                        if(target-arr[i]<0)break;
                        temp.push_back(arr[i]);
                        bt(i,arr,target-arr[i],temp);
                        temp.pop_back();
                }
        }
public:
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
            vector<int>temp;
            bt(0,arr,target,temp);
            return res;
    }
};