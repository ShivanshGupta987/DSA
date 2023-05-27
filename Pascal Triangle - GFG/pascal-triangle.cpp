//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        if(n==1) return {1};
        if(n==2) return {1,1};
        const int mod = 1e9 + 7;
        vector<ll>res(n),temp(n);
        temp[0]=1,temp[1]=1;
        for(int k=3;k<=n;k++){
            res[0]=1,res[k-1]=1;
            for(int i=1;i<k-1;i++){
                res[i] = (temp[i] + temp[i-1])%(mod);
            }
            temp = res;
        }
        return res;
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends