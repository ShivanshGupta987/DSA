//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        // code here
        int i=n-2;
        for(;i>=0;i--){
            if(arr[i]<arr[i+1])break;
        }
        
        if(i==-1){
            int l=0,r=n-1;
            while(l<r){
                swap(arr[l++],arr[r--]);
            }
            return arr;
        }
        
        int j=n-1;
        while(i<j){
            if(arr[j]>arr[i])break;
            j--;
        }
        swap(arr[i],arr[j]);
        int l=i+1,r=n-1;
        while(l<r){
            swap(arr[l++],arr[r--]);
        }
        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends