// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
   public:
   int lenOfLongSubarr(int A[],  int N, int K) 
   { 
   int sum=0;
   unordered_map<int,int> vec;
   
   int i=0,j=0,mx=0;   
   for(int i=0;i<N;i++){
       sum += A[i];
       if(sum == K) mx = max(mx,i+1);
       if(vec.find(sum) == vec.end()) vec[sum] = i;
       if(vec.find(sum - K) != vec.end()) mx = max(mx,i-vec[sum - K]);
   }
   
   return mx;
   }

};

// { Driver Code Starts.

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
}  // } Driver Code Ends