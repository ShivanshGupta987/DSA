//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


long long getSum(int [],int n);
main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		cout<<getSum(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this method */
int f(int n){
    if(n==0 || n==1)return 1;
    return n*f(n-1);
}

long long getSum(int arr[],int n)
{
    //Your code here
    const int mod = (int)1e9+7;
    long s=0;
    for(int i=0;i<n;i++){
        s+=arr[i];
    }
    long mul = f(n-1);
    long sum=0;
    long p=0;
    for(int i=0;i<n;i++){
        long v = mul*s*pow(10,p++);
        v%=mod;
        sum+=v;
        sum%=mod;
    }
    return sum;
    
}