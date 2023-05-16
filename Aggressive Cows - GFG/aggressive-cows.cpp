//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        
        int l=0,r=1e9+1;
        while(l+1<r){
            // mid=possible maxi minimum distance
            int mid = (l+r)/2;
            int cows=1;
            int last_cow_ind=0;
            for(int i=1;i<n;i++){
                int dist = stalls[i]-stalls[last_cow_ind];
                if(dist>=mid){
                    cows++;
                    last_cow_ind=i;
                }
            }
            
            if(cows>=k){
                l=mid;
            }
            else r=mid;
        }
        return l;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends