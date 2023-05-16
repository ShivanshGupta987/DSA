//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestDivisor(vector<int>& nums, int K) {

        // Write your code here.
        int n =nums.size();
        int l=0,r=1e9+1;
        while(l+1<r){
            int mid = (l+r)/2;
            int score=0;
            for(auto & x : nums){
                score += (x/mid) + !(x%mid==0);
            }
            if(score>K){
                l=mid;
            }
            else r=mid;
        }
        if(r==1e9+1)r=-1;
        return r;
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
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends