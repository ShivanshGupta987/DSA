//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        // Complete the function
        unordered_map<int,int>mp;
        int max_len = 0;
        int sum=0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            sum += arr[i];
            if(mp.count(sum-k)){
                max_len = max(max_len,i-mp[sum-k]);
            }
            if(mp.count(sum)==0){
                mp[sum]=i;
            }
        }
        return max_len;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends