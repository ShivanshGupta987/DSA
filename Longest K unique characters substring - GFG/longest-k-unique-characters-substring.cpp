//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int max_len = -1;
        int n = s.size();
        unordered_map<int,int>cnt;
        int start = 0;
        for(int end=0;end<n;end++){
            cnt[s[end]]++;
            while(cnt.size()>k && start < end){
                cnt[s[start]]--;
                if(cnt[s[start]]==0) cnt.erase(s[start]);
                start++;
            }
            if(cnt.size()==k){
                max_len = max(max_len,end-start+1);
            }
        }
        return max_len;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends