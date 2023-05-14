//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int target = x;
	    int first_pos;
	    int l=-1,r=n;
	    while(l+1<r){
	        int mid = (l+r)/2;
	        //predicate(mid)==0
	        if(arr[mid]<target){
	            l=mid;
	        }
	        else r=mid;
	    }
	    if(r!=n && arr[r]==target){
	        first_pos=r;
	    }
	    else return 0;
	    
	    l=-1,r=n;
	    while(l+1<r){
	        int mid = (l+r)/2;
	        //predicate(mid)==0
	        if(arr[mid]<=target){
	            l=mid;
	        }
	        else r=mid;
	    }
	    return (l-first_pos+1);
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends