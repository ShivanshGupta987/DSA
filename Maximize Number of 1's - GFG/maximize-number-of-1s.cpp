//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        // code here
        int ans = 0;
        int zero_cnt = 0;
        int j=0;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                ans = max(ans,i-j+1);
            }
            else{
                zero_cnt++;
                while(zero_cnt>m && j<=i){
                    if(arr[j]==0)zero_cnt--;
                    j++;
                }
                ans = max(ans,i-j+1);
            }
        }
        return ans;
    }  
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends