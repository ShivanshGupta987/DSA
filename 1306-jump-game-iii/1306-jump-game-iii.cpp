class Solution {
public:
        // TC: O(N)   // every element is visited atmost once
        // SC: O(N)   // in worst case e.g. - [1,1,1,1,1,0]
    bool canReach(vector<int>& arr, int i) {
        return i>=0 && i<arr.size() && arr[i]>=0 && (!(arr[i]=-arr[i]) || canReach(arr,i-arr[i]) || canReach(arr,i+arr[i]));
    }
};


// TC: O(N)
// SC: O(N)
// class Solution {
//         private: 
//         bool rec(vector<int>&arr,int i,vector<bool>&a){
//                 int n=arr.size();
//                 if(i<0 || i>=n || a[i]==true)return false;
//                 if(arr[i]==0)return true;
//                 a[i]=true;
//           return rec(arr,i+arr[i],a) || rec(arr,i-arr[i],a);
          
//         }
// public:
//     bool canReach(vector<int>& arr, int start) {
//          vector<bool>a(arr.size(),false);      
//         return rec(arr,start,a);
//     }
// };