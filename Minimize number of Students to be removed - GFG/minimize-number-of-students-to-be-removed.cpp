//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    // TC : O(N^2)
  public:
    int removeStudents(int H[], int N) {
        // code here
        // int ans=0;
        // if(N==1)return 0;
        // vector<int>dp(N,1);
        // for(int i=0;i<N;i++){
        //     for(int j=0;j<i;j++){
        //         if(H[j]<H[i]) dp[i] = max(dp[i],dp[j]+1);
        //         ans = max(ans,dp[i]);
        //     }
        // }
        // return N-ans;
        
        if(N==1)return 0;
        vector<int>tail(N,0); // to keep track of the active list
        tail[0]=H[0];
        int length=1; // always point to empty slot in the tail
        for(int i=1;i<N;i++){
            auto it = lower_bound(tail.begin(),tail.begin()+length,H[i]);
            if(it==tail.begin()+length){
                tail[length++]=H[i];
            }
            else *it=H[i];
        }
        
        return N-length;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends