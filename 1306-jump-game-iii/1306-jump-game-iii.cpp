class Solution {
public:
        // simulating bfs using queue
        Solution(){
                ios::sync_with_stdio(false);
                cin.tie(0);
                cout.tie(0);
        }
    bool canReach(vector<int>& arr, int start) {
            int n=arr.size();
        queue<int>q;
            q.push(start);
            while(!q.empty()){
                 int i=q.front();
                 q.pop();
                    
                 if(arr[i]==0)return true;
                  
                 int ni=i-arr[i]; // new_index      
                 if(ni>=0 && ni<n && arr[ni]!=-1)q.push(ni);
                 
                 ni =i+arr[i]; 
                 if(ni>=0 && ni<n && arr[ni]!=-1)q.push(ni);
                    
                arr[i]=-1;
            }
            return false;
    }
};


// class Solution {
// public:
//         // TC: O(N)   // every element is visited atmost once
//         // SC: O(N)   // in worst case e.g. - [1,1,1,1,1,0]
//     bool canReach(vector<int>& arr, int i) {
//         return i>=0 && i<arr.size() && arr[i]>=0 && (!(arr[i]=-arr[i]) || canReach(arr,i-arr[i]) || canReach(arr,i+arr[i]));
//     }
// };


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