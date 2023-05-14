//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
    int bs(vector<int>& nums){
        int n = nums.size();
        int l=-1,r=n;
        while(l+1<r){
            int mid = (l+r)/2;
            // predicate(mid)==0
            if(nums[mid]==0){
                l=mid;
            }
            else r=mid;
        }
        return r;
    }
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int first_row_ind=-1;
	    int max_ones=0;
	    for(int i=0;i<arr.size();i++){
	        int ones = m-bs(arr[i]);
	        if(ones>max_ones){
	            first_row_ind=i;
	            max_ones=ones;
	        }
	    }
	    return first_row_ind;
	    
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends