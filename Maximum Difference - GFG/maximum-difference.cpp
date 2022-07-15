// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method */
    vector<int> leftsmaller(int arr[], int n){
        vector<int>ls(n);
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && s.top()>=arr[i]){
                s.pop();
            }
            if(s.empty()) ls[i] = 0;
            else ls[i] = s.top();
            s.push(arr[i]);
        }
        return ls;
    }
    int findMaxDiff(int a[], int n)
    {
      //Your code here
      
     
      vector<int>ls = leftsmaller(a,n);
      reverse(a,a+n);
      vector<int>rs = leftsmaller(a,n);
      int res = -1;
      for(int i=0;i<n;i++){
          res=max(res,abs(ls[i]-rs[n-i-1]));
      }
      return res;
      
      
    }
};

// { Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   	int n;
   	cin>>n;
   	int a[n];
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	Solution ob;
   	cout<<ob.findMaxDiff(a,n)<<endl;
   }
    return 0;
}


  // } Driver Code Ends