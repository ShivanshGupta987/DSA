//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string minWindow(string s, string t) {
        // Write your Code here
        int min_len = INT_MAX;
        int ind=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[0] || (s.size()-i)<t.size()) continue;
            int k=0;
            int j=i;
            for(;j<s.size();j++){
                if(s[j]==t[k]){
                    k++;
                    if(k==t.size())break;
                }
            
            }
            if(k==t.size() && (j-i+1) < min_len){
                min_len = (j-i+1);
                ind = i;
            }
        }
        return min_len==INT_MAX?"":s.substr(ind,min_len);
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends