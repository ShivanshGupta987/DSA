//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int leastWeightCapacity(int arr[], int N, int D) {
        // code here
        int l=0,r=1e8;
        while(l+1<r){
            int mid_cap = (l+r)/2;
            int days=1;
            int cur_cap=0;
            bool flag = false;
            for(int i=0;i<N;i++){
                if(arr[i]>mid_cap){
                    flag = true;break;
                }
                if(cur_cap+arr[i]<=mid_cap){
                    cur_cap+=arr[i];
                }
                else{
                    days++;
                    cur_cap=arr[i];
                }
            }
            if(flag){
                l=mid_cap;
                continue;
            }
            if(days>D){
                l=mid_cap;
            }
            else r=mid_cap;
        }
        return r;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends