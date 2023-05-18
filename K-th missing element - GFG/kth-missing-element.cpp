//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int a[], int n, int k)
{
    // Complete the function
    int missing = 0;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1])continue;
        if(missing + a[i]-a[i-1]-1>=k){
            return (k-missing+a[i-1]);
        }
        missing += a[i]-a[i-1]-1;
    }
    return -1;
}