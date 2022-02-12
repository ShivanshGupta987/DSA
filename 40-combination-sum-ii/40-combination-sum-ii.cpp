class Solution {
        vector<vector<int>>res;
        void bt(vector<int>&arr,vector<int>&temp,int target,int ind){
               if(target==0){res.push_back(temp);return;}
                for(int i=ind;i<arr.size();i++){
                        if(i>ind && arr[i]==arr[i-1])continue;
                        if(target-arr[i]<0 )break;
                        temp.push_back(arr[i]);
                        bt(arr,temp,target-arr[i],i+1);
                        temp.pop_back();
                }
        }
public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
            sort(arr.begin(),arr.end());
            vector<int>temp;
            bt(arr,temp,target,0);
            return res;
    }
};