//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    long long modTask(long long n) {
        // code here
        if(n%2==1) n+=1;
        else n+=2;
        return n>>1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.modTask(N) << endl;
    }
    return 0;
}
// } Driver Code Ends